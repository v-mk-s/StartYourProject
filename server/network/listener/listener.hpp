#pragma once

#include "router.hpp"

#include <boost/beast/core.hpp>
#include <boost/asio/strand.hpp>

namespace beast = boost::beast;
namespace net = boost::asio;

using tcp = boost::asio::ip::tcp;


class Listener : public std::enable_shared_from_this<Listener> {
 public:
    Listener(net::io_context& ioc, tcp::endpoint endpoint,
        std::shared_ptr<std::string const> const& doc_root);

    void run();

 private:
    net::io_context& ioc_;
    tcp::acceptor acceptor_;
    std::shared_ptr<std::string const> doc_root_;
    

    void do_accept();
    void on_accept(beast::error_code ec, tcp::socket socket);
};
