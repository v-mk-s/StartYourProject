#pragma once
#include "login_uc.hpp"
#include "register_uc.hpp"

class NetworkRequirements {
public:
    virtual void makeRequest();
};

class Net {
public:
    // login
    int sendLoginData(LoginData login);
    
    // register
    int sendRegisterData(RegisterData register);

private:
    QtNetworkManager* networkmanager;
    LoginUC login_usecase;
    RegisterUC register_usecase;

};