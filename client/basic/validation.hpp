#pragma once

#include "client_utils.hpp"
#include <regex>

#define EMAIL_MIN 2
#define EMAIL_MAX 32
#define USERNAME_MIN 2
#define USERNAME_MAX 32
#define PASSWORD_MIN 8
#define PASSWORD_MAX 64
#define AGE_MIN 14
#define AGE_MAX 200
#define TAG_MAX 32
#define NAME_MIN 2
#define NAME_MAX 32
#define SURNAME_MIN 2
#define SURNAME_MAX 32

// enum class MINMAX
// {
// #define EMAIL_MIN 2
// #define EMAIL_MAX 32
// #define USERNAME_MIN 2
// #define USERNAME_MAX 32
// #define PASSWORD_MIN 8
// #define PASSWORD_MAX 64
// #define AGE_MIN 14
// #define AGE_MAX 200
// #define TAG_MAX 32
// };

// std::string stop_symbols_email = "!#$%^&*()=+',/[]{}:;\"<>?/";
// std::string stop_symbols_username = "!@#$%^&*()_-=+',./[]{}:;\"<>?/";
// std::string stop_symbols_password = "@#$%^&*()_-=+',./[]{}:;\"<>/";

bool isValidEmail(std::string &email);
bool isValidUsername(std::string &username);
bool isValidPassword(std::string &password);

bool isValidAgeToFrom(std::int32_t age_to, std::int32_t age_from);
bool isValidPostTags(std::vector<std::string> &post_tags);

bool isValidPhoto(std::vector<std::int32_t> &photo);
bool isValidName(std::string &name);
bool isValidSurname(std::string &surname);
bool isValidUserDescription(std::string &description);

// may be redundant or Alex functions
bool isValidProjectDescription(std::string &project_description);
bool isValidRequestDescription(std::string &request_description);
bool isValidTeamName(std::string &team_name);
bool isValidProjectName(std::string &project_name);
bool isValidProjectNames(std::vector<std::string> &project_names);
bool isValidTeammates(std::vector<std::string> &teammates);
bool isValidDiversity(std::int32_t diversity);
bool isValidQuestion(std::string &question);
bool isValidProjects(std::vector<NotificationProjectData> &projects);
bool isValidSearchData(std::string &search_data);
bool isValidPostData(MainPostData &post_data);
// redundant, simple check english box or list of supported languages
// bool isValidLanguage(std::string &language);
