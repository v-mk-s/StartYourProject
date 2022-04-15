#pragma once
#include "clientui.hpp"
#include "network.hpp"
#include <string>

typedef struct {
    std::string username;
    std::string password;
} LoginData;

typedef struct {
    std::string email;
    std::string username;
    std::string password;
} RegisterData;

class RegisterUC {
public:
    RegisterUC(RegisterData _register_data = {0}) : register_data(_register_data) {}

    void pushRegisterButton();

    bool getRegisterData();

    void goToRegisterDisplay();

// private:
    UiRequirements ui;
    NetworkRequirements net;
    RegisterData register_data;
};

class LoginUC {
public:
    LoginUC(LoginData _login_data = {0}) : login_data(_login_data) {}

    void pushLoginButton();

    bool getLoginData(LoginData login);

    void goToLoginDisplay();

// private:
    UiRequirements ui;
    NetworkRequirements net;
    LoginData login_data;
};
