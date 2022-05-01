#pragma once
#include <string>

struct LoginData {
    std::string username;
    std::string password;

    LoginData(std::string _username = "", std::string _password = "") : username(_username), password(_password) {}
};

struct RegisterData {
    std::string email;
    std::string username;
    std::string password;

    RegisterData(std::string _email = "", std::string _username = "", std::string _password = "") : email(_email), username(_username), password(_password) {}
};

enum class ErrorStatus {
    error,
    noError
};
