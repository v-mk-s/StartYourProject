#pragma once
#include <string>

struct LoginData {
    std::string username;
    std::string password;
};

struct RegisterData {
    std::string email;
    std::string username;
    std::string password;
};

enum class ErrorStatus {
    error,
    noError
};
