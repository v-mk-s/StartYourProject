#pragma once

#include "client_utils.hpp"



bool isValidEmail(std::string);
bool isValidUsername(std::string);
bool isValidPassword(std::string);
bool isValidName(std::string);
bool isValidSurname(std::string);
bool isValidDescription(std::string);
bool isValidProjectDescription(std::string);
bool isValidRequestDescription(std::string);
bool isValidTeamName(std::string);
bool isValidProjectName(std::string);
bool isValidProjectNames(std::vector<std::string>);
bool isValidPostTags(std::vector<std::string>);
bool isValidTeammates(std::vector<std::string>);
bool isValidDiversity(int);
bool isValidQuestion(std::string);
bool isValidProjects(std::vector<NotificationProjectData>);
bool isValidSearchData(std::string);
bool isValidPostData(MainPostData);
bool isValidAgeFrom(int);
bool isValidAgeTo(int);
bool isValidLanguage(std::string);
