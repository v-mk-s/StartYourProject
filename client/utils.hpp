#pragma once
#include <string>

struct LoginData {
    std::string username;
    std::string password;
};

struct RegisterData : public LoginData {
    std::string email;
    // std::string username;
    // std::string password;
};
