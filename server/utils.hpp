#pragma once

#include <string>


enum class ErrorStatus {
    error,
    noError
};

// enum class RequestType {
//     unnown,
//     login,
//     register_user,
//     edit_profile,
//     publish_post,
//     logout,
//     get_main_page,
//     subscribe,
//     check_diversity,
//     del_user,
//     del_post
// };

// enum class ResponseType {
//     unnown,
//     error,
//     work,
//     done
// };


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


// struct ResponseData;


// template <typename MessageTypeEnum, typename MessageDataStruct>
// struct Message {
//     using Type = MessageTypeEnum;
//     using Data = MassageDataStruct;

//     Type type;
//     Data data;

//     Messege(Type type, Data data): type(type), data(data) {}
// };


// using Request = Message<RequestType>;
// using Response = Message<ResponseType>;
