#include "server.hpp"


Server::ServerImpl::ServerImpl(boost::asio::ip::address address, unsigned short port,
               std::shared_ptr<std::string> doc_root, int threads):
            address_(address), port_(port), doc_root_(doc_root), n_threads_(threads),
            ioc_(threads), signals_(net::signal_set(ioc_, SIGINT, SIGTERM)), database_(&sql_conn_) {
    threads_.reserve(n_threads_ - 1);

    handlers_.emplace(LOGIN_URL, std::make_unique<LoginHandler<JSON>>(&database_));
    handlers_.emplace(REGISTER_URL, std::make_unique<RegisterHandler<JSON>>(&database_));

    handlers_.emplace(EDIT_PROFILE_URL, std::make_unique<EditProfileHandler<JSON>>(&database_));
    handlers_.emplace(DELETE_PROFILE_URL, std::make_unique<DelUserProfileHandler<JSON>>(&database_));
    handlers_.emplace(GET_PROFILE_URL, std::make_unique<GetUserProfileHandler<JSON>>(&database_));
    handlers_.emplace(FIND_USER_URL, std::make_unique<SearchPersonHandler<JSON>>(&database_));
    handlers_.emplace(GET_NOTIFICATIONS_URL, std::make_unique<ShowNotificationsHandler<JSON>>(&database_));

    handlers_.emplace(EDIT_POST_URL, std::make_unique<EditPostHandler<JSON>>(&database_));
    handlers_.emplace(FIND_POST_URL, std::make_unique<SearchPostHandler<JSON>>(&database_));
    handlers_.emplace(MAKE_REQUEST_URL, std::make_unique<MakeRequestToPostHandler<JSON>>(&database_));
    handlers_.emplace(DELETE_POST_URL, std::make_unique<DeletePostHandler<JSON>>(&database_));
    handlers_.emplace(ANSWER_REQUEST_URL, std::make_unique<AnswerTheRequestHandler<JSON>>(&database_));
    handlers_.emplace(CREATE_POST_URL, std::make_unique<CreatePostHandler<JSON>>(&database_));
}

void Server::ServerImpl::start() {
    std::make_shared<Listener>(ioc_, tcp::endpoint{address_, port_}, doc_root_, handlers_)->run();

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
