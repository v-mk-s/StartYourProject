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

// class IReceiveData {
// public:
//     virtual std::string getEditLabelData();
// };

// need impl correspond interface classes (ILoginUseCase)



// Alex's part
class LoginUC : public ILoginUseCase
{
public:
    ErrorStatus onLoginButtonPress(LoginData login) override;

private:
    ErrorStatus isValidLoginData(LoginData login) const;
};

class RegisterUC : public IRegisterUseCase
{
public:
    ErrorStatus onRegisterButton(RegisterData reg) override;

private:
    ErrorStatus isValidRegisterData(RegisterData reg) const;
};

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

// divide front members: Vlad's part

// class MainUC : IClientUseCase {
// public:
//     MainUC(SearchData _search_data = {0}) : search_data(_search_data) {}
//     ErrorStatus onSearchButton(SearchData &search_data);

// private:
//     SearchData search_data;
//     // IClientUseCase* usecase;
// };

// class PublishPostUC : IClientUseCase
// {
// public:
//     PublishPostUC(PublishPostData _publish_post_data = {0}) : publish_post_data(_publish_post_data) {}
//     ErrorStatus onPublishPostButton(PublishPostData &publish_post_data);

// private:
//     PublishPostData publish_post_data;
//     // IClientUseCase* usecase;
// };

// class UserEditUC : IClientUseCase
// {
// public:
//     UserEditUC(UserEditData _user_edit_data = {0}) : user_edit_data(_user_edit_data) {}
//     ErrorStatus onUserEditButton(UserEditData &user_edit_data);

// private:
//     UserEditData user_edit_data;
//     // IClientUseCase* usecase;
// };

// class UserUC : IClientUseCase
// {
// public:
//     UserUC(UserData _user_data = {0}) : user_data(_user_data) {}
//     ErrorStatus onUserButton(UserData &user_data);

// private:
//     UserData user_data;
//     // IClientUseCase* usecase;
// };

// class PhotoUC : IClientUseCase
// {
// public:
//     PhotoUC(PhotoData _photo_data = {0}) : photo_data(_photo_data) {}
//     ErrorStatus onPhotoButton(PhotoData &photo_data);

// private:
//     PhotoData photo_data;
//     // IClientUseCase* usecase;
// };

// class ProjectUC : IClientUseCase
// {
// public:
//     ProjectUC(ProjectData _project_data = {0}) : project_data(_project_data) {}
//     ErrorStatus onProjectButton(ProjectData &project_data);

// private:
//     ProjectData project_data;
//     // IClientUseCase* usecase;
// };

// class NotificationUC : IClientUseCase
// {
// public:
//     NotificationUC(NotificationData _notify_data = {0}) : notify_data(_notify_data) {}
//     ErrorStatus onNotificationButton(NotificationData &notify_data);

// private:
//     NotificationData notify_data;
//     // IClientUseCase* usecase;
// };

// class MainUC : IClientUseCase {
// public:
//     MainUC(SearchData _search_data = {0}) : search_data(_search_data) {}
//     ErrorStatus onSearchButton(SearchData &search_data);

// private:
//     SearchData search_data;
//     // IClientUseCase* usecase;
// };

// class PublishPostUC : IClientUseCase
// {
// public:
//     PublishPostUC(PublishPostData _publish_post_data = {0}) : publish_post_data(_publish_post_data) {}
//     ErrorStatus onPublishPostButton(PublishPostData &publish_post_data);

// private:
//     PublishPostData publish_post_data;
//     // IClientUseCase* usecase;
// };

// class UserEditUC : IClientUseCase
// {
// public:
//     UserEditUC(UserEditData _user_edit_data = {0}) : user_edit_data(_user_edit_data) {}
//     ErrorStatus onUserEditButton(UserEditData &user_edit_data);

// private:
//     UserEditData user_edit_data;
//     // IClientUseCase* usecase;
// };

// class UserUC : IClientUseCase
// {
// public:
//     UserUC(UserData _user_data = {0}) : user_data(_user_data) {}
//     ErrorStatus onUserButton(UserData &user_data);

// private:
//     UserData user_data;
//     // IClientUseCase* usecase;
// };

// class PhotoUC : IClientUseCase
// {
// public:
//     PhotoUC(PhotoData _photo_data = {0}) : photo_data(_photo_data) {}
//     ErrorStatus onPhotoButton(PhotoData &photo_data);

// private:
//     PhotoData photo_data;
//     // IClientUseCase* usecase;
// };

// class ProjectUC : IClientUseCase
// {
// public:
//     ProjectUC(ProjectData _project_data = {0}) : project_data(_project_data) {}
//     ErrorStatus onProjectButton(ProjectData &project_data);

// private:
//     ProjectData project_data;
//     // IClientUseCase* usecase;
// };

// class NotificationUC : IClientUseCase
// {
// public:
//     NotificationUC(NotificationData _notify_data = {0}) : notify_data(_notify_data) {}
//     ErrorStatus onNotificationButton(NotificationData &notify_data);

// private:
//     NotificationData notify_data;
//     // IClientUseCase* usecase;
// };
