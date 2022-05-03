#pragma once
#include "clientui.hpp"
#include "usecases.hpp"

#include <functional>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>



class INet {
public:
    virtual void onMakeRequest(const void* data) = 0;  // тут вопрос (1)
    virtual void onGetResponse(QNetworkReply* reply) = 0;
};

class RegisterNet : public INet {
public:
    RegisterNet(RegisterUC* _usecase = {0}) : usecase(_usecase) {}

    void onMakeRequest(usecase.getData()) override;  // тут вопрос (1)
    void onGetResponse(QNetworkReply* reply) override;

private:
    // IClientUseCase* usecase;  --- тут вопрос (2)
    RegisterUC* usecase;

};

class LoginNet {
public:
    LoginNet(LoginUC* _usecase = {0}) : usecase(_usecase) {}

private:
    // IClientUseCase* usecase;
    LoginUC* usecase;
};
