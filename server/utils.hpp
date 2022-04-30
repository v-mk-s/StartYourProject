#pragma once

#include <string>


enum class ErrorStatus {
    error,
    noError
};



struct PostData {
    int user_id;
    std::string projectname;
    std::string postdescription;
    std::string tags;
    std::string teamname;
};

struct RequestToPostData {
    int user_id;
    int post_id;
    std::string motivation_words;
};

struct UserData {
    std::string username;
    std::string email;
    std::string name;
    std::string sur_name;
    std::string user_discription;
    std::string password;
};