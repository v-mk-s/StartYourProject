#pragma once

#include "router.hpp"
#include "utils.hpp"
#include "server_usecases.hpp"


class IHandler {
 public:
    virtual void Handle(RequestInterface request, ResponseInterface response) = 0;
};


class LoginHandler: public IHandler {
 public:
    LoginHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface request, ResponseInterface response);

 private:
    IServerUseCases* usecase;
};


class RegisterHandler: public IHandler {
 public:
    RegisterHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface request, ResponseInterface response);

 private:
    IServerUseCases* usecase;
};


class EditProfileHandler: public IHandler {
 public:
    EditProfileHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface request, ResponseInterface response);

 private:
    IServerUseCases* usecase;
};

class GetUserProfileHandler: public IHandler {
 public:
    GetUserProfileHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface request, ResponseInterface response);

 private:
    IServerUseCases* usecase;
};
