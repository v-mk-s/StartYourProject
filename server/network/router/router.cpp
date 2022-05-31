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
    Request<http::string_body> request(req);
    Response<http::string_body> response;

    if(req.target().empty() || req.target()[0] != '/' ||
       req.target().find("..") != beast::string_view::npos) {
        response.set_error_message(ResponseStatus::bad_req);
        return send(std::move(response.get_reference()));
    }

    std::cout << "target: " << req.target() << std::endl;

    beast::string_view target = req.target();

    auto handler = handlers.find(target.to_string());
    if (handler != handlers.end()) {
        try {
            handler->second->handle(&request, &response);

        } catch (boost::wrapexcept<boost::system::system_error> const& err) {
            std::cerr << "JSON exeption: " << err.what() << std::endl;
            response.set_error_message(ResponseStatus::bad_req);

        } catch (boost::wrapexcept<std::invalid_argument> const& err) {
            std::cerr << "JSON exeption: " << err.what() << std::endl;
            response.set_error_message(ResponseStatus::bad_req);

        } catch (mysqlx::abi2::r0::Error const& err) {
            std::cerr << "DB exeption: " << err.what() << std::endl;
            response.set_error_message(ResponseStatus::server_error);
        }
    }
    else {
        response.set_error_message(ResponseStatus::bad_req);
    }

    return send(std::move(response.get_reference()));
}
