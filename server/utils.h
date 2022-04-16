#pragma once

#include <string>


enum class ErrorStatus {
    error,
    noError
};



struct PostData {
    int user_id;
    std::string projectname=string();
    std::string postdescription=string();
    std::string tags=string();
    std::string teamname=string();


};

struct RequestToPostData {
    int user_id;
    int post_id;
    std::string motivation_words=string();
};

