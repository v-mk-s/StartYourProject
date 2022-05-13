#pragma once

#include "router.hpp"
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
    LoginHandler() = default;
    LoginHandler(ILoginUC* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    ILoginUC* usecase = nullptr;
};

template <typename JSON>
class RegisterHandler: public IHandler {
 public:
    RegisterHandler() = default;
    RegisterHandler(IRegisterUC* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IRegisterUC* usecase = nullptr;
};

template <typename JSON>
class EditProfileHandler: public IHandler {
 public:
    EditProfileHandler() = default;
    EditProfileHandler(IEditProfileUC* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IEditProfileUC* usecase = nullptr;
};

template <typename JSON>
class DelUserProfileHandler: public IHandler {
 public:
    DelUserProfileHandler() = default;
    DelUserProfileHandler(IDelUserProfileUC* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IDelUserProfileUC* usecase = nullptr;
};

template <typename JSON>
class GetUserProfileHandler: public IHandler {
 public:
    GetUserProfileHandler() = default;
    GetUserProfileHandler(IGetUserProfileUC* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IGetUserProfileUC* usecase = nullptr;
};


/////////////////////////// Posts Handlers ////////////////////////////////

class EditPostHandler: public IHandler {
 public:
    EditPostHandler(IServerUseCases* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase = nullptr;
};


class SearchPostHandler: public IHandler {
 public:
    SearchPostHandler(IServerUseCases* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase = nullptr;
};


class SearchPersonHandler: public IHandler {
 public:
    SearchPersonHandler(IServerUseCases* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase = nullptr;
};


class MakeRequestToPostHandler: public IHandler {
 public:
    MakeRequestToPostHandler(IServerUseCases* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase = nullptr;
};


class ShowNotificationsHandler: public IHandler {
 public:
    ShowNotificationsHandler(IServerUseCases* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase = nullptr;
};



class AnswerTheRequestHandler: public IHandler {
 public:
    AnswerTheRequestHandler(IServerUseCases* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase = nullptr;
};



class DeletePostHandler: public IHandler {
 public:
    DeletePostHandler(IServerUseCases* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IServerUseCases* usecase = nullptr;
};
