#pragma once
#include "../client_UI_UC/client_ui.hpp"
#include "../client_UI_UC/client_usecases.hpp"
// #include <QtNetwork/QNetworkAccessManager>
// #include <QtNetwork/QNetworkReply>


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
