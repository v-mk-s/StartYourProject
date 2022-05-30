#include "router.hpp"

using beast::iequals;


template<bool isRequest, class Body, class Fields>
void Session::send_lambda::operator()(http::message<isRequest, Body, Fields>&& msg) const {
    auto sp = std::make_shared<http::message<isRequest, Body, Fields>>(std::move(msg));

    self_.res_ = sp;

    http::async_write(self_.stream_, *sp, beast::bind_front_handler(
            &Session::on_write,
            self_.shared_from_this(),
            sp->need_eof()
        )
    );
}


void Session::run() {
    net::dispatch(stream_.get_executor(), beast::bind_front_handler(
            &Session::do_read,
            shared_from_this()
        )
    );
}

void Session::do_read() {
    req_ = {};
    stream_.expires_after(std::chrono::seconds(30));

    http::async_read(stream_, buffer_, req_, beast::bind_front_handler(
            &Session::on_read,
            shared_from_this()
        )
    );
}

void Session::on_read(beast::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    if(ec == http::error::end_of_stream) {
        return do_close();
    }

    if(ec) {
        std::cerr << "read" << ": " << ec.message() << "\n";
        return;
    }

    handle_request(*doc_root_, std::move(req_), lambda_, handlers_);
}

void Session::on_write(bool close, beast::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    if(ec) {
        std::cerr << "write" << ": " << ec.message() << "\n";
        return;
    }
    if(close) {
        return do_close();
    }

    res_ = nullptr;
    do_read();
}

void Session::do_close() {
    beast::error_code ec;
    stream_.socket().shutdown(tcp::socket::shutdown_send, ec);
}


template<class Body, class Allocator, class Send>
void handle_request(beast::string_view doc_root,
    http::request<Body, http::basic_fields<Allocator>>&& req,
    Send&& send,
    const std::map<std::string, std::unique_ptr<IHandler>>& handlers) {
    auto const bad_request = [&req](beast::string_view why) {
        http::response<http::string_body> res{http::status::bad_request, req.version()};
        res.set(http::field::server, SERVER_NAME);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        res.body() = std::string(why);
        res.prepare_payload();
        return res;
    };

    auto const server_error = [&req]() {
        http::response<http::string_body> res{http::status::internal_server_error, req.version()};
        res.set(http::field::server, SERVER_NAME);
        res.keep_alive(req.keep_alive());
        return res;
    };

    auto const wrong_data = [&req](beast::string_view why) {
        http::response<http::string_body> res{http::status::bad_request, req.version()};
        res.set(http::field::server, SERVER_NAME);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        res.body() = std::string(why);
        res.prepare_payload();
        return res;
    };

    if(req.target().empty() || req.target()[0] != '/' ||
       req.target().find("..") != beast::string_view::npos) {
        return send(bad_request("Illegal request-target"));
    }

    std::cout << "target: " << req.target() << std::endl;

    beast::string_view target = req.target();
    Request<http::string_body> request(req);
    Response<http::string_body> response;

    auto handler = handlers.find(target.to_string());
    if (handler != handlers.end()) {
        try {
            handler->second->handle(&request, &response);
        } catch (boost::wrapexcept<boost::system::system_error> err) {
            std::cerr << err.what() << std::endl;
            std::cerr << "JSON exeption: " << err.what() << std::endl;
        } catch (mysqlx::abi2::r0::Error err) {
            std::cerr << "DB exeption: " << err.what() << std::endl;
            return send(server_error());
        }
    }
    else {
        return send(bad_request("Unknown target\n"));
    }

    return send(std::move(response.get_reference()));
}
