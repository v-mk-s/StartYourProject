#pragma once

#include "utils.hpp"


class IServerUseCases {
 public:
    virtual ErrorStatus checkUserInDB(LoginData user) = 0;
    virtual ErrorStatus addUserToDB(RegisterData user_data) = 0;
    virtual ErrorStatus editUserData(UserData user_data) = 0;
    virtual ErrorStatus delUserData(std::string username) = 0;
    virtual ErrorStatus getUserData(std::string username) = 0;
};


class LoginUC {
 public:
    ErrorStatus checkUserInDB(LoginData user);
};


class RegisterUC {
 public:
    ErrorStatus addUserToDB(RegisterData user_data);
};


class EditProfileUC {
 public:
    ErrorStatus editUserData(UserData user_data);
};


class DelUserProfileUC {
 public:
    ErrorStatus delUserData(std::string username);
};
