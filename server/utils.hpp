#pragma once

#include <string>


enum class ErrorStatus {
    unnown,
    no_error,
    error,
    wrong_data
};


struct LoginData {
    std::string username;
    std::string password;
};

struct RegisterData {
    std::string username;
    std::string password;
    std::string email;
};

struct UserData {
    std::string username;
    std::string email;
    std::string name;
    std::string sur_name;
    std::string user_discription;
    std::string password;
};


template <typename MessageDataStruct>
struct Message {
    ErrorStatus type = ErrorStatus::unnown;
    MessageDataStruct data = MessageDataStruct();

    Message() = default;
    Message(ErrorStatus type, MessageDataStruct data): type(type), data(data) {}
};
