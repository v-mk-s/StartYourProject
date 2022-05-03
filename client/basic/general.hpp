#pragma once

class IUIRequirements {
public:
    virtual void showError() = 0;
    virtual void showSuccess() = 0;
    virtual void showMainDisplay() = 0;
    virtual void showRegisterDisplay() = 0;
    virtual void showLoginDisplay() = 0;
    virtual void showUserEditDisplay() = 0;
    virtual void showUserDisplay() = 0;
    virtual void showProjectDisplay() = 0;
    virtual void showPublishPostDisplay() = 0;
    virtual void showNotificationDisplay() = 0;
};
