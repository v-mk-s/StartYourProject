#pragma once

#include <string>
#include <vector>
#include <sstream>

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


struct ProjectDescriptionData
{
    std::string project_id; // like username, but for internal DB

    ProjectDescriptionData(
        std::string _project_id = nullptr
    ) :
        project_id(_project_id)
    {
    }
};


struct UserDescriptionData
{
    std::string username;

    UserDescriptionData(
        std::string _username = nullptr
    ) :
        username(_username)
    {
    }
};


struct PhotoData
{
    std::vector<std::int32_t> photo;

    PhotoData(
        std::vector<std::int32_t> _photo = {}
    ) :
        photo(_photo)
    {
    }
};


struct UserEditData // 6+1
{
    std::string username;
    std::string email;
    std::string name;
    std::string surname;
    std::string user_description;
    std::string password;
    PhotoData photo_data;

    UserEditData(
        std::string _username = nullptr,
        std::string _email = nullptr,
        std::string _name = nullptr,
        std::string _surname = nullptr,
        std::string _user_description = nullptr,
        std::string _password = nullptr,
        PhotoData _photo_data = PhotoData()
    ) :
        username(_username),
        email(_email),
        name(_name),
        surname(_surname),
        user_description(_user_description),
        password(_password),
        photo_data(_photo_data)
    {
    }
};

// don't delete, data for refactoring

struct LoginData
{
    std::string username;
    std::string password;

    LoginData(
        std::string _username = nullptr,
        std::string _password = nullptr
    ) :
        username(_username),
        password(_password)
    {
    }
    
    bool operator==(const LoginData& other) const {
        return username == other.username && password == other.password;
    }
};


struct RegisterData
{
    std::string email;
    std::string username;
    std::string password;

    RegisterData(
        std::string _email = nullptr,
        std::string _username = nullptr,
        std::string _password = nullptr
    ) :
        email(_email),
        username(_username),
        password(_password)
    {
    }
    
    bool operator==(const RegisterData& other) const {
        return username == other.username && password == other.password && email == other.email;
    }
};

struct UserData {
    std::string username;
    std::string email;
    std::string name;
    std::string surname;
    std::string user_description;
    std::string password;

    UserData(
        std::string _username = nullptr,
        std::string _email = nullptr,
        std::string _name = nullptr,
        std::string _surname = nullptr,
        std::string _user_description = nullptr,
        std::string _password = nullptr
    ) :
        username(_username),
        email(_email),
        name(_name),
        surname(_surname),
        user_description(_user_description),
        password(_password)
    {
    }

    bool operator==(const UserData& other) const {
        return username == other.username && email == other.email &&
                name == other.name && surname == other.surname &&
                user_description == other.user_description && password == other.password;
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
    std::string motivation_words;
    enum class Status {yes, no, unknown};
    Status status;

    bool operator==(const RequestToPostData& other) const {
        return user_id == other.user_id && 
               post_id == other.post_id;
    }

    RequestToPostData(
    ) :
        user_id(0),
        post_id(0),
        motivation_words(nullptr)
    {
    }
};


struct PublishPostData
{
    std::string project_name;
    std::string team_name;
    std::vector<std::string> post_tags;
    std::vector<std::string> teammates;
    std::string project_description;

    PublishPostData(
        std::string _project_name = nullptr,
        std::string _team_name = nullptr,
        std::vector<std::string> _post_tags = {},
        std::vector<std::string> _teammates = {},
        std::string _project_description = nullptr
    ) :
        project_name(_project_name),
        team_name(_team_name),
        post_tags(_post_tags),
        teammates(_teammates),
        project_description(_project_description)
    {
    }
};


struct ProjectData
{
    std::string project_name;
    std::string team_name;
    std::vector<std::string> post_tags;
    std::vector<std::string> teammates;
    std::string project_description;
    double diversity;
    std::string request_description;

    ProjectData(
        std::string _project_name = nullptr,
        std::string _team_name = nullptr,
        std::vector<std::string> _post_tags = {},
        std::vector<std::string> _teammates = {},
        std::string _project_description = nullptr,
        double _diversity = 0,
        std::string _request_description = nullptr
    ) :
        project_name(_project_name),
        team_name(_team_name),
        post_tags(_post_tags),
        teammates(_teammates),
        project_description(_project_description),
        diversity(_diversity),
        request_description(_request_description)
    {
    }

    bool operator==(const ProjectData& other) const {
        return project_name == other.project_name;
    }

};


struct NotificationProjectData
{
    std::string project_name;
    std::string name;
    std::string username;
    std::string description;
    std::string question;
    std::vector<std::string> teammates;

    NotificationProjectData(
        std::string _project_name = nullptr,
        std::string _name = nullptr,
        std::string _username = nullptr,
        std::string _description = nullptr,
        std::string _question = nullptr,
        std::vector<std::string> _teammates = {}
    ) :
        project_name(_project_name),
        name(_name),
        username(_username),
        description(_description),
        question(_question),
        teammates(_teammates)
    {
    }
};


struct NotificationData
{
    std::vector<NotificationProjectData> projects;

    NotificationData(
        std::vector<NotificationProjectData> _projects = {}
    ) :
        projects(_projects)
    {
    }
};


struct MainPostData
{
    std::string search_data;
    std::string team_name;
    std::string project_name;
    std::vector<std::string> post_tags;
    std::string project_description;

    MainPostData(
        std::string _search_data = nullptr,
        std::string _team_name = nullptr,
        std::string _project_name = nullptr,
        std::vector<std::string> _post_tags = {},
        std::string _project_description = nullptr
    ) :
        search_data(_search_data),
        team_name(_team_name),
        project_name(_project_name),
        post_tags(_post_tags),
        project_description(_project_description)
    {
    }
};
