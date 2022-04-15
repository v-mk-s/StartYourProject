#pragma once
#include "network.hpp"

class ClientUI {
public:
    ClientUI();
    virtual ~ClientUI() = default;

// private:
    QtWidget* ui;
    LoginUC login_uc;
    RegisterUC register_uc;
};

class UiRequirements {
public:
    virtual void showError();
    virtual void showSuccess();
    virtual void showMainDisplay();

};
