#pragma once
#include "clientui.hpp"
#include "general.hpp"

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
