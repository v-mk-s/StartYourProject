#pragma once
#include "gmock/gmock.h"
#include "clientui.hpp"
#include "general.hpp"

// class LoginUC {
// public:
//     LoginUC(LoginData _login_data = {0}) : login_data(_login_data) {}

//     LoginData pushLoginButton(std::string& username, std::string& password);

//     bool getLoginData(LoginData login);

//     void goToLoginDisplay();

// // private:
//     UiRequirements ui;
//     NetworkRequirements net;
//     LoginData login_data;
// };

class MockLoginUC : public LoginUC {
public:
    MOCK_METHOD1(onLoginButton, ErrorStatus(LoginData user_data));
};

class MockRegisterUC : public RegisterUC {
public:
    MOCK_METHOD1(onRegisterButton, ErrorStatus(RegisterData user_data));
};

class LoginUC {
public:
    ErrorStatus onLoginButton(LoginData user_data);

private:
    IClientUseCase* usecase;
};

class RegisterUC {
public:
    ErrorStatus onRegisterButton(RegisterData reg_data);

private:
    IClientUseCase* usecase;
};