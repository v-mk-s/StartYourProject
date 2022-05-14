#pragma once

#include "utils.hpp"

// global class: usual buttons on almost every page
class IParentUseCase
{
public:
    virtual ErrorStatus onLogOutButton() = 0;
    virtual ErrorStatus onHelpButton() = 0;
    virtual ErrorStatus onBackButton() = 0;
    virtual ErrorStatus onToMainPageButton() = 0;
};

// for each usecase own interface class


// display_3 // Vlad
class IMainUseCase : public IParentUseCase
{
public:
    // Inherit from IParentUseCase
    // virtual ErrorStatus onLogOutButton() = 0;
    // virtual ErrorStatus onHelpButton() = 0;
    // virtual ErrorStatus onBackButton() = 0;

    // delete
    // virtual ErrorStatus onToMainPageButton() = 0;

    virtual ErrorStatus onEditProfileButton() = 0;
    virtual ErrorStatus onSearchButton(SearchData search_data) = 0;
    virtual ErrorStatus onPrevPageButton() = 0;
    virtual ErrorStatus onNextPageButton() = 0;
    virtual ErrorStatus onProjectDescriptionButton(ProjectDescriptionData project_description_data) = 0;
    virtual ErrorStatus onFindMyDiversityTeamsButton(SearchData search_data) = 0;
    virtual ErrorStatus onNotificationButton() = 0;
    virtual ErrorStatus onPublishPostButton() = 0;
};

// display_4  // Alex
class IProjectUseCase : public IParentUseCase
{
public:
    virtual ErrorStatus onEditProfileButton(RegisterData reg) = 0;
};

// display_5 // Vlad
class IPublishPostUseCase : public IParentUseCase
{
public:
    // Inherit from IParentUseCase
    // virtual ErrorStatus onLogOutButton() = 0;
    // virtual ErrorStatus onHelpButton() = 0;
    // virtual ErrorStatus onBackButton() = 0;
    // virtual ErrorStatus onToMainPageButton() = 0;

    virtual ErrorStatus onPhotoUploadButton(PhotoData photo_data) = 0;
    virtual ErrorStatus onSaveProfileButton(UserEditData user_edit_data) = 0;
};

// display_6 // Vlad
class IUserUseCase : public IParentUseCase
{
    // Inherit from IParentUseCase
    // virtual ErrorStatus onLogOutButton() = 0;
    // virtual ErrorStatus onHelpButton() = 0;
    // virtual ErrorStatus onBackButton() = 0;
    // virtual ErrorStatus onToMainPageButton() = 0;

    virtual ErrorStatus onEditProjectButton(ProjectDescriptionData project_description_data) = 0;
    virtual ErrorStatus onDelButton(ProjectDescriptionData project_description_data) = 0;
};

// display_7  // Alex
class IUseCase : public IParentUseCase
{
public:
    virtual ErrorStatus onEditProfileButton(RegisterData reg) = 0;
};

// display_8 // Vlad
class INotificationUseCase : public IParentUseCase
{
public:
    // Inherit from IParentUseCase
    // virtual ErrorStatus onLogOutButton() = 0;
    // virtual ErrorStatus onHelpButton() = 0;
    // virtual ErrorStatus onBackButton() = 0;
    // virtual ErrorStatus onToMainPageButton() = 0;

    virtual ErrorStatus onProjectNameProjectButton(ProjectDescriptionData project_description_data) = 0;
    virtual ErrorStatus onTeamNameProjectButton(ProjectDescriptionData project_description_data) = 0;
    virtual ErrorStatus onProjectProjectDescriptionButton(ProjectDescriptionData project_description_data) = 0;

    virtual ErrorStatus onProjectNameUserButton(UserDescriptionData user_description_data) = 0;
    virtual ErrorStatus onTeamNameUserButton(UserDescriptionData user_description_data) = 0;
    virtual ErrorStatus onProjectDescriptionUserButton(UserDescriptionData user_description_data) = 0;

    virtual ErrorStatus onPrevPageButton() = 0;
    virtual ErrorStatus onNextPageButton() = 0;
};

// display_9 // Vlad
class ITeamPhotosUseCase : public IParentUseCase
{
public:
    // Inherit from IParentUseCase
    // virtual ErrorStatus onLogOutButton() = 0;
    // virtual ErrorStatus onHelpButton() = 0;
    // virtual ErrorStatus onBackButton() = 0;
    // virtual ErrorStatus onToMainPageButton() = 0;

    virtual ErrorStatus onPrevPageButton() = 0;
    virtual ErrorStatus onNextPageButton() = 0;
};

// display_10 // Vlad
class IHelpUseCase : public IParentUseCase
{
public:
    // Inherit from IParentUseCase
    // virtual ErrorStatus onLogOutButton() = 0;
    // virtual ErrorStatus onHelpButton() = 0;
    // virtual ErrorStatus onBackButton() = 0;

    // delete
    // virtual ErrorStatus onHelpButton() = 0;

    virtual ErrorStatus onPrevPageButton() = 0;
    virtual ErrorStatus onNextPageButton() = 0;
};

class ILoginUseCase {
public:
    virtual ErrorStatus onLoginButton(LoginData login) = 0;

};

class IRegisterUseCase {
public:
    virtual ErrorStatus onRegisterButton(RegisterData reg) = 0;

};

class IProject {
public:
    virtual ErrorStatus onRequestToProjectButton(ProjectData request) = 0;

};

class IPublishPost {
public:
    virtual ErrorStatus onGetDataButton(PublishPostData save) = 0;

};
