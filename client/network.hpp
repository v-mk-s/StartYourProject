#pragma once
#include "clientui.hpp"
#include "usecases.hpp"
// #include <QtNetwork/QNetworkAccessManager>
// #include <QtNetwork/QNetworkReply>


class INet {
public:
    virtual void Dispatch(IRequest request, std::function<void(IResponse)>) = 0;
};

class RegisterNet {
public:
    void Dispatch(IRequest request, std::function<void(IResponse)>);

private:
    IClientUseCase* usecase;
};

class LoginNet {
public:
    void Dispatch(IRequest request, std::function<void(IResponse)>);

private:
    IClientUseCase* usecase;
};
