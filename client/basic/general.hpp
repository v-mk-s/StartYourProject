#pragma once

class UiRequirements {
public:
    virtual void showError();
    virtual void showSuccess();
    virtual void showMainDisplay();
    virtual void showRegisterDisplay();
    virtual void showLoginDisplay();
    virtual void showUserEditDisplay();
    virtual void showUserDisplay();
    virtual void showProjectDisplay();
    virtual void showPublishPostDisplay();
    virtual void showNotificationDisplay();
};

class NetworkRequirements {
public:
    virtual void makeRequest();
};
