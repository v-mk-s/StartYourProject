#pragma once
#include <string>
#include <vector>

struct LoginData {
    std::string username;
    std::string password;

    LoginData(std::string _username = "", std::string _password = "") : username(_username), password(_password) {}
};

struct RegisterData {
    std::string email;
    std::string username;
    std::string password;

    RegisterData(std::string _email = "", std::string _username = "", std::string _password = "") : email(_email), username(_username), password(_password) {}
};
// using namespace std;

struct UserEditData {
    std::string username;
    std::string email;
    std::string name;
    std::string surname;
    std::string description;
    std::string password;
};

struct PhotoData {
    std::array<int> photo;
};

struct UserData {
    std::string username;
    std::string email;
    std::string name;
    std::string surname;
    std::string description;
    std::vector<std::string> project_names;
};

struct PublishPostData {
    std::string project_name;
    std::string team_name;
    std::vector<std::string> post_tags;
    std::vector<std::string> teammates;
    std::string project_description;
};

struct ProjectData {
    std::string project_name;
    std::string team_name;
    std::vector<std::string> post_tags;
    std::vector<std::string> teammates;
    std::string project_description;
    double diversity;
    std::string request_description;
};

typedef struct NotificationProjectData {
    std::string project_name;
    std::string name;
    std::string username;
    std::string description;
    std::string question;
    std::vector<std::string> teammates;
} NotificationProjectData;

struct NotificationData {
    std::vector<NotificationProjectData> projects;
};

struct MainPostData {
    std::string search_data;
    std::string team_name;
    std::string project_name;
    std::vector<std::string> post_tags;
    std::string project_description;
};

struct MainData {
    MainPostData post_data;
    bool competition;
    bool hackathon;
    bool start_up;
    int age_from;
    int age_to;
    std::string language;
    std::vector<std::string> post_tags;
    bool diversity;
};

enum class ErrorStatus {
    error,
    noError
};
