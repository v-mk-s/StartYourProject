#pragma once

#include "usecases.hpp"
#include "validation.hpp"
#include <sstream>

// ErrorStatus LoginUC::onLoginButton() {
//     // get corresponding info from bars
//     std::string username = getEditLabelData();
//     std::string password = getEditLabelData();

//     if (    !isValidUsername(username) ||
//             !isValidPassword(password))
//     {
//         // mb show error window
//         return ErrorStatus::error;
//     }

//     login_data_.username = username;
//     login_data_.password = password;

//     return ErrorStatus::noError;
// }

ErrorStatus LoginUC::isValidLoginData(LoginData login) const {
    if (!isValidUsername(login.username)) {
        return ErrorStatus::username_not_valid;
    }

    if (!isValidPassword(login.password)) {
        return ErrorStatus::password_not_valid;
    }

    return ErrorStatus::no_error;
}

ErrorStatus LoginUC::onLoginButtonPress(LoginData login) {
    ErrorStatus check_input_struct = isValidLoginData(login);
    if (check_input_struct != ErrorStatus::no_error) {
        return check_input_struct;
    }

    // get json_data from struct login
    
    return ErrorStatus::no_error;
}

ErrorStatus RegisterUC::isValidRegisterData(RegisterData reg) const {
    if (!isValidUsername(reg.username)) {
        return ErrorStatus::username_not_valid;
    }

    if (!isValidPassword(reg.password)) {
        return ErrorStatus::password_not_valid;
    }

    if (!isValidEmail(reg.email)) {
        return ErrorStatus::email_not_valid;
    }

    return ErrorStatus::no_error;
}


ErrorStatus RegisterUC::onRegisterButton(RegisterData reg) {
    ErrorStatus check_input_struct = isValidRegisterData(reg);
    if (check_input_struct != ErrorStatus::no_error) {
        return check_input_struct;
    }

    // get json_data from struct reg

    return ErrorStatus::no_error;
}
