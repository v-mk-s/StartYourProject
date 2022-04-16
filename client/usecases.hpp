#pragma once
#include "clientui.hpp"
// #include "general.hpp"

class LoginUC : IClientUseCase {
public:
    LoginUC(LoginData _login_data = {0}) : login_data(_login_data) {}
    ErrorStatus onLoginButton(LoginData& login_data);

private:
    LoginData login_data;
    // IClientUseCase* usecase;
};

class RegisterUC : IClientUseCase {
public:
    RegisterUC(RegisterData _reg_data = {0}) : reg_data(_reg_data) {}
    ErrorStatus onRegisterButton(RegisterData& reg_data);

private:
    RegisterData reg_data;
    // IClientUseCase* usecase;
};