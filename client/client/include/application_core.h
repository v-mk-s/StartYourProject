#ifndef APPLICATIONCORE_H
#define APPLICATIONCORE_H

#include "login_page.h"
#include "register_page.h"
#include "project_page.h"
#include "publish_post_page.h"
#include "user_edit_page.h"
#include "user_page.h"
#include "utils.hpp"
#include "general.h"
#include <QWidget>

#include <memory>


class ApplicationCore
{
public:
    ApplicationCore();

    // gets for UserData
//    std::string getUserAuthToken() { return user_data.auth_token; }
//    std::string getUserUsername() { return user_data.username; }
//    std::string getUserEmail() { return user_data.email; }
//    std::string getUserName() { return user_data.name; }
//    std::string getUserSurname() { return user_data.sur_name; }
//    std::string getUserUserDescription() { return user_data.user_discription; }
//    std::string getUserPassword() { return user_data.password; }
//    std::vector<std::string> getUserProjects() { return user_data.projects; }

//    // sets for Userdata
//    void setUserAuthToken(std::string auth_token) { user_data.auth_token = auth_token; }
//    void setUserUsername(std::string username) { user_data.username = username; }
//    void setUserEmail(std::string email) { user_data.email = email; }
//    void setUserSurname(std::string surname) { user_data.sur_name = surname; }
//    void setUserUserDescription(std::string user_description) { user_data.user_discription = user_description; }
//    void setUserPassword(std::string password) { user_data.password = password; }
//    void setUserName(std::string name) { user_data.name = name; }
//    void setUser(std::vector<std::string> projects) { user_data.projects = projects; }

//    // gets for ProjectData
//    std::string getProjectUsername() { return user_data.username; }
//    std::string getProjectProjectName() { return project_data.project_name;}
//    std::string getProjectTeamName() { return project_data.team_name; }
//    std::vector<std::string> getProjectPostTags() { return project_data.post_tags; }
//    std::vector<std::string> getProjectTeammates() { return project_data.teammates; }
//    std::string getProjectProjectDescription() { return project_data.project_description; }

//    // sets for ProjectData
//    void setProjectUsername(std::string username) { project_data.username = username; }
//    void setProjectProjectName(std::string project_name) { project_data.project_name = project_name; }
//    void setProjectTeamName(std::string team_name) { project_data.team_name = team_name; }
//    void setProjectPostTags(std::vector<std::string> post_tags) { project_data.post_tags = post_tags; }
//    void setProjectTeammates(std::vector<std::string> teammates) { project_data.teammates = teammates; }
//    void setProjectProjectDescription(std::string project_description) { project_data.project_description = project_description; }

    LoginPage* getLoginPage() { return login_ui; }
//    RegisterPage* getRegisterPage() { return register_ui; }

private:
//    RegisterPage* register_ui;
      LoginPage* login_ui;
      std::shared_ptr<Context> _context;

//      QWidget* login_window;

//    ProjectPage* project_ui;
//    PublishPostPage* publish_post_ui;
//    UserEditPage* user_edit_ui;
//    UserPage* user_ui;

};

#endif // APPLICATIONCORE_H
