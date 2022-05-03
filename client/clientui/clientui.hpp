#pragma once

#include "client_utils.hpp"



class IClientUseCase {
public:
    virtual ErrorStatus onLoginButton() = 0;
    virtual ErrorStatus onRegisterButton() = 0;

    virtual ErrorStatus onSearchButton(MainData search_data) = 0;
    virtual ErrorStatus onPublishPostButton(PublishPostData publish_post_data) = 0;
    virtual ErrorStatus onUserEditButton(UserEditData user_edit_data) = 0;
    virtual ErrorStatus onUserButton(UserData user_data) = 0;
    virtual ErrorStatus onPhotoButton(PhotoData photo_data) = 0;
    virtual ErrorStatus onProjectButton(ProjectData project_data) = 0;
    virtual ErrorStatus onNotificationButton(NotificationData notify_data) = 0;

    // QWindow* ui;
};
