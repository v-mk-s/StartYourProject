#pragma once

#include "clientui.hpp"
#include "general.hpp"
#include "client_utils.hpp"



// class IReceiveData {
// public:
//     virtual std::string getEditLabelData();
// };


// need impl correspond interface classes (ILoginUseCase)

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


// divide front members: Vlad's part


// class MainUC : IClientUseCase {
// public:
//     MainUC(MainData _search_data = {0}) : search_data(_search_data) {}
//     ErrorStatus onSearchButton(MainData &search_data);

// private:
//     MainData search_data;
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
