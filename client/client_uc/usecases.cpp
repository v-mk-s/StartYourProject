#pragma once

#include "usecases.hpp"
#include "validation.hpp"

ErrorStatus LoginUC::onLoginButton() {
    // get corresponding info from bars
    std::string username = ui->username->text();
    std::string password = ui->password->text();

    if (    !isValidUsername(username) ||
            !isValidPassword(password))
    {
        // mb show error window
        return ErrorStatus::error;
    }

    login_data.username = username;
    login_data.password = password;

    return ErrorStatus::noError;
}

ErrorStatus RegisterUC::onRegisterButton() {
    std::string email =     ui->email->text();
    std::string username =  ui->username->text();
    std::string password =  ui->password->text();

    if (    !isValidUsername(username) ||
            !isValidPassword(password) ||
            !isValidEmail(email))
    {
        // QMessageBox::about(this, "Error", "Incorrect input data");
        return ErrorStatus::error;
    }

    reg_data.email =    email;
    reg_data.username = username;
    reg_data.password = password;

    return ErrorStatus::noError;
}

const RegisterData& RegisterUC::getData() const {
    return reg_data;
}
