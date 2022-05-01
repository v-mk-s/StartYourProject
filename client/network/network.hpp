#pragma once
#include "../clientui/clientui.hpp"
#include "../client_uc/usecases.hpp"
#include <functional>
// #include <QtNetwork/QNetworkAccessManager>
// #include <QtNetwork/QNetworkReply>

class IRequest {};
class IResponse {};

class INet {
public:
    virtual void Dispatch(IRequest request, std::function<void(IResponse)>) = 0;
};

class RegisterNet {
public:
    RegisterNet(IClientUseCase* _usecase) : usecase(_usecase) {}
    void Dispatch(IRequest request, std::function<void(IResponse)>);

private:
    IClientUseCase* usecase;
};

class LoginNet {
public:
    LoginNet(IClientUseCase* _usecase) : usecase(_usecase) {}
    void Dispatch(IRequest request, std::function<void(IResponse)>);

private:
    IClientUseCase* usecase;
};
