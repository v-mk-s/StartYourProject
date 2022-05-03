#include "validation.hpp"

bool isValidEmail(std::string email) {
    if (email.find("@") == -1) {
        return false;
    }

    for (auto c : email) {
        if (stop_symbols_email.find(c) != -1) {
            return false;
        }
    }

    return true;
}

bool isValidUsername(std::string username) {
    for (auto c : username) {
        if (stop_symbols_username.find(c) != -1) {
            return false;
        }
    }
    return true;
}

bool isValidPassword(std::string password) {
    if (password.size() < 8) {
        return false;
    }

    return true;
}
