#ifndef GENERAL_H
#define GENERAL_H

#include <vector>
#include <string>
#include "utils.hpp"
#include <memory>

class general
{
public:
    general();
};

std::vector<std::string> getVectorFromString(const std::string& string);

struct Context {
    UserData _user_data;
    ProjectData _project_data;

    UserData& getUserData() { return _user_data; }
    ProjectData& getProjectData() { return _project_data; }

    void setAuthTokenUserData(const std::string& key) { _user_data.auth_token = key; }
    void setUsernameUserData(const std::string& key) { _user_data.username = key; }
    void setEmailUserData(const std::string& key) { _user_data.email = key; }
    void setNameUserData(const std::string& key) { _user_data.name = key; }
    void setSurnameUserData(const std::string& key) { _user_data.sur_name = key; }
    void setUserDescriptionUserData(const std::string& key) { _user_data.user_discription = key; }
    void setPasswordUserData(const std::string& key) { _user_data.password = key; }
    void setProjectsUserData(const std::vector<std::string>& key) { _user_data.projects = key; }

    void setUsernameProjectData(const std::string& key) { _project_data.username = key; }
    void setProjectNameProjectData(const std::string& key) { _project_data.project_name = key; }
    void setTeamNameProjectData(const std::string& key) { _project_data.team_name = key; }
    void setPostTagsProjectData(const std::vector<std::string>& key) { _project_data.post_tags = key; }
    void setTeammatesProjectData(const std::vector<std::string>& key) { _project_data.teammates = key; }
    void setProjectDescriptionProjectData(const std::string& key) { _project_data.username = key; }

};

#endif // GENERAL_H
