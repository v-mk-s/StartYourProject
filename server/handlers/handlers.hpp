#pragma once

#include "router.hpp"
#include "utils.hpp"
#include "server_usecases.hpp"


class IHandler {
 public:
    virtual void Handle(RequestInterface* request, ResponseInterface* response) = 0;
};


/////////////////////// User Handlers ///////////////////////////////////

class LoginHandler: public IHandler {
 public:
    LoginHandler() = default;
    LoginHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase = nullptr;
};


class RegisterHandler: public IHandler {
 public:
    RegisterHandler() = default;
    RegisterHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase = nullptr;
};


class EditProfileHandler: public IHandler {
 public:
    EditProfileHandler() = default;
    EditProfileHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase = nullptr;
};


class DelUserProfileHandler: public IHandler {
 public:
    DelUserProfileHandler() = default;
    DelUserProfileHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase = nullptr;
};


class GetUserProfileHandler: public IHandler {
 public:
    GetUserProfileHandler() = default;
    GetUserProfileHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase = nullptr;
};


/////////////////////////// Posts Handlers ////////////////////////////////

class EditPostHandler: public IHandler {
 public:
    EditPostHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase;
};


class SearchPostHandler: public IHandler {
 public:
    SearchPostHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase;
};


class SearchPersonHandler: public IHandler {
 public:
    SearchPersonHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase;
};


class MakeRequestToPostHandler: public IHandler {
 public:
    MakeRequestToPostHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase;
};


class ShowNotificationsHandler: public IHandler {
 public:
    ShowNotificationsHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase;
};



class AnswerTheRequestHandler: public IHandler {
 public:
    AnswerTheRequestHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase;
};



class DeletePostHandler: public IHandler {
 public:
    DeletePostHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase;
};
