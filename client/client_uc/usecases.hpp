#pragma once

#include "clientui.hpp"
#include "general.hpp"
#include "client_utils.hpp"

#define WRONG_AGE "Wrong age: TENET?"
#define WRONG_NAME "Username is incorrect"
#define WRONG_PASSWORD "Password is incorrect"
#define WRONG_EMAIL "Email is incorrect"
#define LOGIN_DATA_DONT_MATCH "Username and password dont match"
#define SAME_USER "A user with the same name already exists"



// Vlad's part

// display_3
class MainUC : public IMainUseCase
{
public:
    // Inherit from IParentUseCase
    ErrorStatus onLogOutButton() override;
    ErrorStatus onHelpButton() override;
    ErrorStatus onBackButton() override;

    ErrorStatus onEditProfileButton() override;
    ErrorStatus onNextPageButton() override;
    ErrorStatus onSearchButton(SearchData search_data) override;
    ErrorStatus onPrevPageButton() override;
    ErrorStatus onNextPageButton() override;
    ErrorStatus onProjectDescriptionButton(ProjectDescriptionData project_description_data) override;
    ErrorStatus onFindMyDiversityTeamsButton(SearchData search_data) override;
    ErrorStatus onNotificationButton() override;
    ErrorStatus onPublishPostButton() override;

private:
    ErrorStatus isValidSearchData(SearchData search_data) const;
};

// display_5 // Vlad
class PublishPostUC : public IPublishPostUseCase
{
public:
    // Inherit from IParentUseCase
    ErrorStatus onLogOutButton() override;
    ErrorStatus onHelpButton() override;
    ErrorStatus onBackButton() override;
    ErrorStatus onToMainPageButton() override;

    ErrorStatus onPhotoUploadButton(PhotoData photo_data) override;
    ErrorStatus onSaveProfileButton(UserEditData user_edit_data) override;

private:
    ErrorStatus isValidPhotoData(PhotoData photo_data) const;
    ErrorStatus isValidUserEditData(UserEditData user_edit_data) const;
};

// display_6 // Vlad
class UserUC : public IUserUseCase
{
    // Inherit from IParentUseCase
    ErrorStatus onLogOutButton() override;
    ErrorStatus onHelpButton() override;
    ErrorStatus onBackButton() override;
    ErrorStatus onToMainPageButton() override;

    ErrorStatus onEditProjectButton(ProjectDescriptionData project_description_data) override;
    ErrorStatus onDelButton(ProjectDescriptionData project_description_data) override;
};

// display_8 // Vlad
class NotificationUC : public INotificationUseCase
{
public:
    // Inherit from IParentUseCase
    ErrorStatus onLogOutButton() override;
    ErrorStatus onHelpButton() override;
    ErrorStatus onBackButton() override;
    ErrorStatus onToMainPageButton() override;

    ErrorStatus onProjectNameProjectButton(ProjectDescriptionData project_description_data) override;
    ErrorStatus onTeamNameProjectButton(ProjectDescriptionData project_description_data) override;
    ErrorStatus onProjectProjectDescriptionButton(ProjectDescriptionData project_description_data) override;

    ErrorStatus onProjectNameUserButton(UserDescriptionData user_description_data) override;
    ErrorStatus onTeamNameUserButton(UserDescriptionData user_description_data) override;
    ErrorStatus onProjectDescriptionUserButton(UserDescriptionData user_description_data) override;

    ErrorStatus onPrevPageButton() override;
    ErrorStatus onNextPageButton() override;
};

// display_9 // Vlad
class TeamPhotosUC : public ITeamPhotosUseCase
{
public:
    // Inherit from IParentUseCase
    ErrorStatus onLogOutButton() override;
    ErrorStatus onHelpButton() override;
    ErrorStatus onBackButton() override;
    ErrorStatus onToMainPageButton() override;

    ErrorStatus onPrevPageButton() override;
    ErrorStatus onNextPageButton() override;
};

// display_10 // Vlad
class HelpUC : public IHelpUseCase
{
public:
    // Inherit from IParentUseCase
    ErrorStatus onLogOutButton() override;
    ErrorStatus onBackButton() override;
    ErrorStatus onToMainPageButton() override;

    ErrorStatus onPrevPageButton() override;
    ErrorStatus onNextPageButton() override;
};


class LoginUC : public ILoginUseCase {
public:
    ErrorStatus onLoginButton(LoginData login) override;

};

class RegisterUC : public IRegisterUseCase {
public:
    ErrorStatus onRegisterButton(RegisterData reg) override;

};

class ProjectUC : public IProject {
public:
    ErrorStatus onRequestToProjectButton(ProjectData request) override;
    
};

class PublishPostUC : public IPublishPost {
    ErrorStatus onGetDataButton(PublishPostData save) override;

};
