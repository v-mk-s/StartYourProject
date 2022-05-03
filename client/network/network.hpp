#pragma once
#include "clientui.hpp"
#include "usecases.hpp"

#include <functional>
#include <any>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>



class INet {
public:
    virtual void onMakeRequest(std::any data) = 0;
    virtual void onGetResponse(QNetworkReply* reply) = 0;
};

class RegisterNet : public INet {
public:
    RegisterNet(RegisterUC* _usecase = {0}) : usecase(_usecase) {}

    void onMakeRequest(std::any data) override;
    void onGetResponse(QNetworkReply* reply) override;

private:
    // IClientUseCase* usecase;  --- тут вопрос (2)
    RegisterUC* usecase;

};

class LoginNet {
public:
    LoginNet(LoginUC* _usecase = {0}) : usecase(_usecase) {}

    void onMakeRequest(std::any data) override;
    void onGetResponse(QNetworkReply* reply) override;

private:
    // IClientUseCase* usecase;
    LoginUC* usecase;
};
