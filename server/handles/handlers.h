#pragma once

#include "utils.h"
#include "server_usecases.h"

class IHandler {
 public:
    virtual void Handle(RequestInterface request, ResponseInterface response) = 0;
};


class EditPostHandler: public IHandler {
 public:
    EditPostHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface request, ResponseInterface response);

 private:
    IServerUseCases* usecase;
};


class SearchPostHandler: public IHandler {
 public:
    SearchPostHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface request, ResponseInterface response);

 private:
    IServerUseCases* usecase;
};


class SearchPersonHandler: public IHandler {
 public:
    SearchPersonHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface request, ResponseInterface response);

 private:
    IServerUseCases* usecase;
};


class MakeRequestToPostHandler: public IHandler {
 public:
    MakeRequestToPostHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface request, ResponseInterface response);

 private:
    IServerUseCases* usecase;
};


class ShowNotificationsHandler: public IHandler {
 public:
    ShowNotificationsHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface request, ResponseInterface response);

 private:
    IServerUseCases* usecase;
};



class AnswerTheRequestHandler: public IHandler {
 public:
    AnswerTheRequestHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface request, ResponseInterface response);

 private:
    IServerUseCases* usecase;
};



class DeletePostHandler: public IHandler {
 public:
    DeletePostHandler(IServerUseCases* usecase): usecase(usecase) {}

    void Handle(RequestInterface request, ResponseInterface response);

 private:
    IServerUseCases* usecase;
};