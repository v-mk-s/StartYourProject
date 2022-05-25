#include "server.hpp"


class Server::ServerImpl {
 public:
    ServerImpl(boost::asio::ip::address address, unsigned short port,
               std::shared_ptr<std::string> doc_root, int threads);

    void start();

 private:
    boost::asio::ip::address address_;
    unsigned short port_;
    std::shared_ptr<std::string> doc_root_;
    int n_threads_;

    std::map<std::string, IHandler*> handlers_;

    std::shared_ptr<MySQLConnection> sqlconnection_;

    net::io_context ioc_;
    net::signal_set signals_;
    std::vector<std::thread> threads_;
};


Server::Server(boost::asio::ip::address address, unsigned short port, 
               std::shared_ptr<std::string> doc_root, int n_threads):
            impl_(std::make_unique<ServerImpl>(address, port, doc_root, n_threads)) {}

void Server::start() {
    impl_->start();
}


Server::ServerImpl::ServerImpl(boost::asio::ip::address address, unsigned short port,
               std::shared_ptr<std::string> doc_root, int threads):
            address_(address), port_(port), doc_root_(doc_root), n_threads_(threads),
            ioc_{threads}, signals_(net::signal_set(ioc_, SIGINT, SIGTERM)) {
    threads_.reserve(n_threads_ - 1);
}

void Server::ServerImpl::start() {
    std::make_shared<Listener>(ioc_, tcp::endpoint{address_, port_}, doc_root_)->run();

    signals_.async_wait([&] (beast::error_code const&, int) {ioc_.stop();});

    for (int i = n_threads_ - 1; i > 0; --i) {
        threads_.emplace_back([&] {ioc_.run();});
    }
    ioc_.run();

    for (auto& thread : threads_) {
        thread.join();
    }
}
