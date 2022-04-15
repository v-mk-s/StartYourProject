#pragma once

class UiRequirements {
public:
    virtual void showError();
    virtual void showSuccess();
    virtual void showMainDisplay();

};

class NetworkRequirements {
public:
    virtual void makeRequest();
};
