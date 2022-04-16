#pragma once
#include "utils.hpp"

class IClientUseCase {
public:
    virtual ErrorStatus onLoginButton(LoginData user_data);
    virtual ErrorStatus onRegisterButton(RegisterData reg_data);
};
