#pragma once

#include <string>


enum class ErrorStatus {
    error,
    noError
};

enum class RequestType {
    unnown,
    login,
    register_user,
    edit_profile,
    publish_post,
    logout,
    get_main_page,
    subscribe,
    check_diversity,
    del_user,
    del_post
};

enum class ResponseType {
    unnown,
    error,
    work,
    done
};


// Нужно как-то избавиться от копипасты
struct LoginData {
    std::string username;
    std::string password;
};

struct RegisterData: public LoginData {
    // std::string username;
    // std::string password;
    std::string email;
};

struct UserData: public RegisterData {
    // std::string username;
    // std::string email;
    std::string name;
    std::string sur_name;
    std::string user_discription;
    // std::string password;
};


struct ResponseData;


template <typename MassegeTypeEnum, typename MassegeDataStruct>
struct Message {
    using Type = MassegeTypeEnum;
    using Data = MassegeDataStruct;

    Type type;
    Data data;

    Messege(Type type, Data data): type(type), data(data) {}
};


using Request = Message<RequestType, LoginData>;
using Response = Message<ResponseType, ResponseData>;
