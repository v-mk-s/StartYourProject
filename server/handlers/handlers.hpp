#pragma once

#include "router.hpp"
#include "utils.hpp"
#include "server_usecases.hpp"


class IHandler {
 public:
    virtual void Handle(RequestInterface* request, ResponseInterface* response) = 0;
};


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
