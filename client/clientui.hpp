#pragma once
#include "utils.hpp"

// class ClientUI {
// public:
//     ClientUI();
//     virtual ~ClientUI() = default;

// // private:
//     QtWidget* ui;
//     LoginUC login_uc;
//     RegisterUC register_uc;
// };

class IClientUseCase {
public:
    virtual ErrorStatus onLoginButton(LoginData user_data) = 0;
    virtual ErrorStatus onRegisterButton(RegisterData reg_data) = 0;

};
