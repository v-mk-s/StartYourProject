#include "listener.hpp"


Listener::Listener(net::io_context& ioc, tcp::endpoint endpoint,
    std::shared_ptr<std::string const> const& doc_root):
    ioc_(ioc), acceptor_(net::make_strand(ioc)),
    doc_root_(doc_root) {
        beast::error_code ec;

        acceptor_.open(endpoint.protocol(), ec);
        if(ec) {
            std::cerr << "open" << ": " << ec.message() << "\n";
            return;
        }

        acceptor_.set_option(net::socket_base::reuse_address(true), ec);
        if(ec) {
            std::cerr << "set_option" << ": " << ec.message() << "\n";
            return;
        }

        acceptor_.bind(endpoint, ec);
        if(ec) {
            std::cerr << "bind" << ": " << ec.message() << "\n";
            return;
        }

        acceptor_.listen(net::socket_base::max_listen_connections, ec);
        if(ec) {
            std::cerr << "listen" << ": " << ec.message() << "\n";
            return;
        }
}

void Listener::run() {
    do_accept();
}

void Listener::do_accept() {
    acceptor_.async_accept(net::make_strand(ioc_), beast::bind_front_handler(
        &Listener::on_accept,
        shared_from_this())
    );
}

void Listener::on_accept(beast::error_code ec, tcp::socket socket) {
    if(ec) {
        std::cerr << "accept" << ": " << ec.message() << "\n";
        return;
    } else {
        std::make_shared<Session>(std::move(socket), doc_root_)->run();
    }

    do_accept();
}