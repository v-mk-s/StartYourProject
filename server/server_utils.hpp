#pragma once

#include <string>


enum class ErrorStatus {
    ok,
    bad_req,
    not_found,
    server_error,
    wrong_data
};


struct LoginData {
    std::string username;
    std::string password;

    bool operator==(const LoginData& other) const {
        return username == other.username && password == other.password;
    }
};

struct RegisterData {
    std::string username;
    std::string password;
    std::string email;

    bool operator==(const RegisterData& other) const {
        return username == other.username && password == other.password && email == other.email;
    }
};

struct UserData {
    std::string username;
    std::string email;
    std::string name;
    std::string sur_name;
    std::string user_discription;
    std::string password;

    bool operator==(const UserData& other) const {
        return username == other.username && email == other.email &&
                name == other.name && sur_name == other.sur_name &&
                user_discription == other.user_discription && password == other.password;
    }
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



template <typename MessageData>
struct Message {
    ErrorStatus status = ErrorStatus::server_error;
    MessageData data = MessageData();

    Message() = default;
    Message(ErrorStatus status): status(status) {}
    Message(ErrorStatus status, MessageData data): status(status), data(data) {}
};


class IJSON {
 public:
    IJSON(std::string &str);

    template<class T>
    T get(const std::string &str, T);

    template<class T>
    void put(const std::string &str, T);
};
