#pragma once
#include "utils.hpp"

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
