#pragma once

#include "utils.hpp"
#include <regex>
#include <algorithm>

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

#define MAX_PROJECT_NAME 10
#define MAX_PROJECT_SIZE 100
#define MAX_TEAM_NAME 20
#define MAX_REQUEST_SIZE 100
#define MAX_TAG_NAME 10




bool isValidEmail(const std::string &email);
bool isValidUsername(const std::string &username);
bool isValidPassword(const std::string &password);
bool isValidSurname(const std::string &surname);

bool isValidProjectName(const std::string &project_name);
bool isValidTeamName(const std::string &team_name);
bool isValidTeammates(const std::vector<std::string> &teammates);
bool isValidPostTags(const std::vector<std::string> &post_tags);
bool isValidProjectDescription(const std::string &project_description);
bool isValidName(const std::string &name);
bool isValidUserDescription(const std::string &description);



// bool isValidAgeToFrom(const std::int32_t &age_to, const std::int32_t &age_from);

// // bool isValidPhoto(const std::vector<std::int32_t> &photo);

// // bool isValidDescription(const std::string description);
// bool isValidRequestDescription(const std::string &request_description);

// bool isValidProjectNames(const std::vector<std::string> &project_names);

// bool isValidDiversity(const std::int32_t diversity);
// bool isValidQuestion(const std::string &question);
// bool isValidProjects(const std::vector<NotificationProjectData> &projects);
// bool isValidSearchData(const std::string &search_data);
// bool isValidPostData(const MainPostData &post_data);

// bool isValidLanguage(const std::string& language);
