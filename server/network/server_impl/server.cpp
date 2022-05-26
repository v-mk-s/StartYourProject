#include "server.hpp"


Server::ServerImpl::ServerImpl(boost::asio::ip::address address, unsigned short port,
               std::shared_ptr<std::string> doc_root, int threads):
            address_(address), port_(port), doc_root_(doc_root), n_threads_(threads),
            ioc_(threads), signals_(net::signal_set(ioc_, SIGINT, SIGTERM)), database_(&sql_conn_) {
    threads_.reserve(n_threads_ - 1);

    handlers_[LOGIN_URL] = new LoginHandler<JSON>(&database_);
    handlers_[REGISTER_URL] = new RegisterHandler<JSON>(&database_);

    handlers_[EDIT_PROFILE_URL] = new EditProfileHandler<JSON>(&database_);
    handlers_[DELETE_PROFILE_URL] = new DelUserProfileHandler<JSON>(&database_);
    handlers_[GET_PROFILE_URL] = new GetUserProfileHandler<JSON>(&database_);
    handlers_[FIND_USER_URL] = new SearchPersonHandler<JSON>(&database_);
    handlers_[GET_NOTIFICATIONS_URL] = new ShowNotificationsHandler<JSON>(&database_);

    handlers_[EDIT_POST_URL] = new EditPostHandler<JSON>(&database_);
    handlers_[FIND_POST_URL] = new SearchPostHandler<JSON>(&database_);
    handlers_[MAKE_REQUEST_URL] = new MakeRequestToPostHandler<JSON>(&database_);
    handlers_[DELETE_POST_URL] = new DeletePostHandler<JSON>(&database_);
    handlers_[ANSWER_REQUEST_URL] = new AnswerTheRequestHandler<JSON>(&database_);
    handlers_[CREATE_POST_URL] = new CreatePostHandler<JSON>(&database_);
}

void Server::ServerImpl::start() {
    std::make_shared<Listener>(ioc_, tcp::endpoint{address_, port_}, doc_root_,
        std::make_shared<std::map<std::string, IHandler*>>(handlers_))->run();

    signals_.async_wait([&] (beast::error_code const&, int) {ioc_.stop();});

    for (int i = n_threads_ - 1; i > 0; --i) {
        threads_.emplace_back([&] {ioc_.run();});
    }
    ioc_.run();

    for (auto& thread : threads_) {
        thread.join();
    }
}


Server::Server(boost::asio::ip::address address, unsigned short port, 
               std::shared_ptr<std::string> doc_root, int n_threads):
            impl_(std::make_unique<ServerImpl>(address, port, doc_root, n_threads)) {}

void Server::start() {
    impl_->start();
}

Server::ServerImpl::~ServerImpl() {
    for (auto &pair : handlers_) {
        delete pair.second;
    }
}
