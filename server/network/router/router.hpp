#pragma once

#include "request_response.hpp"
#include "handlers.hpp"

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/dispatch.hpp>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;

using tcp = boost::asio::ip::tcp;



class Session : public std::enable_shared_from_this<Session> {
 public:
    Session(tcp::socket&& socket, std::shared_ptr<std::string const> const& doc_root):
        stream_(std::move(socket)),
        doc_root_(doc_root),
        lambda_(*this) {}

    void run();

    void do_read();
    void on_read(beast::error_code ec, std::size_t bytes_transferred);
    void on_write(bool close, beast::error_code ec, std::size_t bytes_transferred);
    void do_close();

 private:
    struct send_lambda {
        Session& self_;

        explicit send_lambda(Session& self): self_(self) {}

        template<bool isRequest, class Body, class Fields>
        void operator()(http::message<isRequest, Body, Fields>&& msg) const;
    };

    beast::tcp_stream stream_;
    beast::flat_buffer buffer_;
    std::shared_ptr<std::string const> doc_root_;
    
    http::request<http::string_body> req_;
    std::shared_ptr<void> res_;

    // Request<http::string_body> req_;
    // Response<http::string_body> res_;

    send_lambda lambda_;
};


template<class Body, class Allocator, class Send>
void handle_request(beast::string_view doc_root, 
    http::request<Body, http::basic_fields<Allocator>>&& req,
    Send&& send
);
