#pragma once

#include <string>


enum class ErrorStatus {
    error,
    noError
};

enum class RequestType {
    unnown,
    login,
    registerUser,
    editProfile,
    publishPost,
    logout,
    getMainPage,
    subscribe,
    checkDiversity,
    delUser,
    delPost
};

enum class ResponseType {
    unnown,
    error,
    work,
    done
};


// Нужно как-то избавиться от копипасты
struct LoginData {
    std::string userName;
    std::string passWord;
};

struct RegisterData {
    std::string userName;
    std::string passWord;
    std::string eMail;
};

struct EditUserData {
    std::string userName;
    std::string eMail;
    std::string name;
    std::string surName;
    std::string userDiscription;
    std::string passWord;
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
