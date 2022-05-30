#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <map>



// Нужно отправить на сервер username и password
/* example:
URL: http://localhost:8080/login
Body    :
{
    "username": "test",
    "password": "qwerty123"
}
*/
// В ответ записывает токен
// Токен нужно записать в поле "auth_token"
#define LOGIN_URL "/login"

// Нужно отправить на сервер username, password и email
#define REGISTER_URL "/register"

// Нужно отправить на сервер заполненную структуру UserData
// В поле "auth_token" должен лежать токен полученный при логировании  
#define EDIT_PROFILE_URL "/profile/edit"

// Нужно отправить на сервер username
// В поле "auth_token" должен лежать токен полученный при логировании  
#define DELETE_PROFILE_URL "/profile/delete"

// Нужно отправить на сервер username
// В ответе заполненная структура UserData, ключи в json совпадают с названиями полей структуры
#define GET_PROFILE_URL "/profile"

// In development
#define FIND_USER_URL "/profile/find"

// In development
#define GET_NOTIFICATIONS_URL "/profile/notifications"



// Нужно отправить на сервер project_name
// В ответе заполненная структура ProjectData, ключи в json совпадают с названиями полей структуры
#define GET_POST_URL "/post/find"

// Нужно отправить на сервер заполненную структуру ProjectData
// По ключу "auth_token" должен лежать токен полученный при логировании
#define CREATE_POST_URL "/post/create"

// Нужно отправить на сервер заполненную структуру ProjectData
// По ключу "auth_token" должен лежать токен полученный при логировании
#define EDIT_POST_URL "/post/edit"

// Нужно отправить на сервер project_name
// По ключу "auth_token" должен лежать токен полученный при логировании
#define DELETE_POST_URL "/post/delete"

// In development
#define MAKE_REQUEST_URL "/post/request/make"
// In development
#define ANSWER_REQUEST_URL "/post/request/answer"


#define CONTENT_TYPE_TEXT "text/plain"
#define CONTENT_TYPE_JSON "application/json"

#define HTTP_VER_1_1 11
#define HTTP_VER_1_0 10


// username == nick, nickname

enum class ErrorStatus
{
    error,
    no_error,
    username_not_valid,
    password_not_valid,
    email_not_valid,
    json_error,
    age_not_valid,
    post_tags_not_valid,
    photo_not_valid,
    name_not_valid,
    surname_not_valid,
    user_description_not_valid,
    project_name_not_valid,
    team_name_not_valid,
    teammates_not_valid,
    project_description_not_valid,
    diversity_not_valid,
    request_description_not_valid,
    photo_data_not_valid
};


// divide front members

struct SearchData // 8
{
    // MainPostData post_data;
    bool competition;
    bool hackathon;
    bool start_up;
    std::int32_t age_from;
    std::int32_t age_to;
    bool language;
    std::vector<std::string> post_tags;
    bool diversity;

    SearchData(
        bool _competition = false,
        bool _hackathon = false,
        bool _start_up = false,
        std::int32_t _age_from = 0,
        std::int32_t _age_to = 0,
        bool _language = false,
        std::vector<std::string> _post_tags = {},
        bool _diversity = false
    ) :
        competition(_competition),
        hackathon(_hackathon),
        start_up(_start_up),
        age_from(_age_from),
        age_to(_age_to),
        language(_language),
        post_tags(_post_tags),
        diversity(_diversity)
    {
    }
};


struct UserData {
    std::string auth_token;
    std::string username;
    std::string email;
    std::string name;
    std::string sur_name;
    std::string user_description;
    std::string password;
    std::vector<std::string> projects;

    UserData() = default;

    bool operator==(const UserData& other) const {
        return auth_token == other.auth_token && username == other.username;
    }
};


struct RequestToPostData {
    std::string project_name;
    std::string motivation_words;
    enum class Status {yes=1, no=2, unknown=3};
    Status status;

    RequestToPostData() = default;
};


struct ProjectData
{
    std::string username;
    std::string project_name;
    std::string team_name;
    std::vector<std::string> post_tags;
    std::vector<std::string> teammates;
    std::string project_description;
    double diversity;

    ProjectData(): diversity(0.0) {}

    bool operator==(const ProjectData& other) const {
        return username == other.username && project_name == other.project_name;
    }
};
