#pragma once

#include "inetwork.hpp"
#include "server_utils.hpp"
#include "server_usecases.hpp"


class IHandler {
 public:
    virtual void handle(RequestInterface* request, ResponseInterface* response) = 0;
};


/////////////////////// User Handlers ///////////////////////////////////

template <typename JSON>
class LoginHandler: public IHandler {
 public:
    LoginHandler() = delete;
    LoginHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    LoginUC usecase;
};


template <typename JSON>
class RegisterHandler: public IHandler {
 public:
    RegisterHandler() = delete;
    RegisterHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    RegisterUC usecase;
};


template <typename JSON>
class EditProfileHandler: public IHandler {
 public:
    EditProfileHandler() = delete;
    EditProfileHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    EditProfileUC usecase;
};


template <typename JSON>
class DelUserProfileHandler: public IHandler {
 public:
    DelUserProfileHandler() = delete;
    DelUserProfileHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    DelUserProfileUC usecase;
};


template <typename JSON>
class GetUserProfileHandler: public IHandler {
 public:
    GetUserProfileHandler() = delete;
    GetUserProfileHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    GetUserProfileUC usecase;
};


/////////////////////////// Posts Handlers ////////////////////////////////

template <typename JSON>
class EditPostHandler: public IHandler {
 public:
    EditPostHandler() = delete;
    EditPostHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    EditPostUC usecase;
};


template <typename JSON>
class SearchPostHandler: public IHandler {
 public:
    SearchPostHandler() = delete;
    SearchPostHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    SearchPostUC usecase;
};


template <typename JSON>
class SearchPersonHandler: public IHandler {
 public:
    SearchPersonHandler() = delete;
    SearchPersonHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    SearchPersonUC usecase;
};


template <typename JSON>
class MakeRequestToPostHandler: public IHandler {
 public:
    MakeRequestToPostHandler() = delete;
    MakeRequestToPostHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    MakeRequestToPostUC usecase;
};


template <typename JSON>
class ShowNotificationsHandler: public IHandler {
 public:
    ShowNotificationsHandler() = delete;
    ShowNotificationsHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    ShowNotificationsUC usecase;
};


template <typename JSON>
class AnswerTheRequestHandler: public IHandler {
 public:
    AnswerTheRequestHandler() = delete;
    AnswerTheRequestHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    AnswerTheRequestUC usecase;
};


template <typename JSON>
class DeletePostHandler: public IHandler {
 public:
    DeletePostHandler() = delete;
    DeletePostHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    DeletePostUC usecase;
};


template <typename JSON>
class CreatePostHandler: public IHandler {
 public:
    CreatePostHandler() = delete;
    CreatePostHandler(IMainDataBase *database): usecase(database) {}

    void handle(RequestInterface* request, ResponseInterface* response) override;

 private:
    CreatePostUC usecase;
};


#include "handlers.impl"
