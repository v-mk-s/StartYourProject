#pragma once

#include "utils.hpp"
#include "database.hpp"


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
    LoginUC() = default;
    LoginUC(DataBase* database): database(database) {}

    ErrorStatus checkUserInDB(LoginData user);

 private:
    DataBase* database = nullptr;
};


class RegisterUC {
 public:
    RegisterUC() = default;
    RegisterUC(DataBase* database): database(database) {}
    ErrorStatus addUserToDB(RegisterData user_data);

 private:
    DataBase* database = nullptr;
};


class EditProfileUC {
 public:
    EditProfileUC() = default;
    EditProfileUC(DataBase* database): database(database) {}

    ErrorStatus editUserData(UserData user_data);

 private:
    DataBase* database = nullptr;
};


class DelUserProfileUC {
 public:
    DelUserProfileUC() = default;
    DelUserProfileUC(DataBase* database): database(database) {}
    ErrorStatus delUserData(std::string username);

 private:
    DataBase* database = nullptr;
};


class GetUserProfileUC {
 public:
    GetUserProfileUC() = default;
    GetUserProfileUC(DataBase* database): database(database) {}

    Message<UserData> getUserData(std::string username);

 private:
    DataBase* database = nullptr;
};
