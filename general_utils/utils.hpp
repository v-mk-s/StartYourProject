#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <map>

#define LOGIN_URL "/login"
#define REGISTER_URL "/register"

#define EDIT_PROFILE_URL "/profile/edit"
#define DELETE_PROFILE_URL "/profile/delete"
#define GET_PROFILE_URL "/profile"
#define FIND_USER_URL "/profile/find"
#define GET_NOTIFICATIONS_URL "/profile/notifications"

#define EDIT_POST_URL "/post/edit"
#define FIND_POST_URL "/post/find"
#define MAKE_REQUEST_URL "/post/request/make"
#define DELETE_POST_URL "/post/delete"
#define ANSWER_REQUEST_URL "/post/request/answer"
#define CREATE_POST_URL "/post/create"

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

    SearchData(bool _competition = false, bool _hackathon = false, bool _start_up = false,
               std::int32_t _age_from = 0, std::int32_t _age_to = 0,
               bool _language = false, std::vector<std::string> _post_tags = {},
               bool _diversity = false) : competition(_competition), hackathon(_hackathon),
                                          start_up(_start_up), age_from(_age_from),
                                          age_to(_age_to), language(_language),
                                          post_tags(_post_tags), diversity(_diversity) {}
};


// struct ProjectDescriptionData
// {
//     std::string project_id; // like username, but for internal DB

//     ProjectDescriptionData(std::string _project_id = "") : project_id(_project_id) {}
// };


// struct UserDescriptionData
// {
//     std::string username;

//     UserDescriptionData(std::string _username = "") : username(_username) {}
// };


// struct PhotoData
// {
//     std::vector<std::int32_t> photo;

//     PhotoData(std::vector<std::int32_t> _photo = {}) : photo(_photo) {}
// };


// struct UserEditData // 6+1
// {
//     std::string username;
//     std::string email;
//     std::string name;
//     std::string surname;
//     std::string user_description;
//     std::string password;
//     PhotoData photo_data;

//     UserEditData(std::string _username = "", std::string _email = "", std::string _name = "",
//                  std::string _surname = "", std::string _user_description = "", std::string _password = "",
//                  PhotoData _photo_data = PhotoData()) : username(_username), email(_email),
//                                                         name(_name), surname(_surname),
//                                                         user_description(_user_description), password(_password),
//                                                         photo_data(_photo_data) {}
// };

// // don't delete, data for refactoring

// struct LoginData
// {
//     std::string username;
//     std::string password;

//     LoginData(std::string _username = "", std::string _password = "") : username(_username), password(_password) {}
    
//     bool operator==(const LoginData& other) const {
//         return username == other.username && password == other.password;
//     }
// };


// struct RegisterData
// {
//     std::string email;
//     std::string username;
//     std::string password;

//     RegisterData(std::string _email = "", std::string _username = "", std::string _password = "") : email(_email), username(_username), password(_password) {}
    
//     bool operator==(const RegisterData& other) const {
//         return username == other.username && password == other.password && email == other.email;
//     }
// };

struct UserData {
    int id;
    std::string auth_token;
    std::string username;
    std::string email;
    std::string name;
    std::string sur_name;
    std::string user_discription;
    std::string password;
    std::vector<std::string> projects;

    UserData(): id(0) {}

    bool operator==(const UserData& other) const {
        return id == other.id && auth_token == other.auth_token && username == other.username;
    }
};

// struct PostData {
//     int user_id;
//     std::string projectname;
//     std::string postdescription;
//     std::string tags;
//     std::string teamname;
// };

struct RequestToPostData {
    int user_id;
    int post_id;
    std::string project_name;
    std::string motivation_words;
    enum class Status {yes=1, no=2, unknown=3};
    Status status;

    bool operator==(const RequestToPostData& other) const {
        return user_id == other.user_id && 
               post_id == other.post_id;
    }
};


// struct PublishPostData
// {
//     std::string project_name;
//     std::string team_name;
//     std::vector<std::string> post_tags;
//     std::vector<std::string> teammates;
//     std::string project_description;
// };


struct ProjectData
{
    int projectid;
    int userid;
    std::string project_name;
    std::string team_name;
    std::vector<std::string> post_tags;
    std::vector<std::string> teammates;
    std::string project_description;
    double diversity;

    ProjectData(): projectid(0), userid(0), diversity(0.0) {}

    bool operator==(const ProjectData& other) const {
        return project_name == other.project_name;
    }
};


struct NotificationProjectData
{
    int projectid;
    std::string project_name;
    std::string name;
    std::string username;
    std::string description;
    std::string question;
    std::vector<std::string> teammates;

    NotificationProjectData(): projectid(0) {}
};


struct NotificationData
{
    std::vector<NotificationProjectData> projects;
};


// struct MainPostData
// {
//     std::string search_data;
//     std::string team_name;
//     std::string project_name;
//     std::vector<std::string> post_tags;
//     std::string project_description;
// };
