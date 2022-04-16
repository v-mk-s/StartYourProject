#pragma once

#include <string>


enum class ErrorStatus {
    unnown,
    no_error,
    error,
    wrong_data
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

// enum class ErrorType {
    
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


template <typename MessageDataStruct>
struct Message {
    ErrorStatus type;
    MessageDataStruct data;

    Messege(ResponseType type, MessageDataStruct data): type(type), data(data) {}
};
