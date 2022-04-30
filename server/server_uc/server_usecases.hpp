#pragma once

#include "utils.hpp"
#include "database.hpp"


class IServerUseCases {
 public:
    // virtual ErrorStatus checkUserInDB(LoginData) = 0;
    // virtual ErrorStatus addUserToDB(RegisterData) = 0;
    // virtual ErrorStatus editUserData(UserData) = 0;
    // virtual ErrorStatus delUserData(std::string) = 0;
    // virtual Message<UserData> getUserData(std::string) = 0;

    virtual ~IServerUseCases() = 0;
};


class LoginUC: public IServerUseCases {
 public:
    LoginUC() = default;
    LoginUC(DataBase* database): database(database) {}

    ErrorStatus checkUserInDB(LoginData user);

 private:
    DataBase* database = nullptr;
};


class RegisterUC: public IServerUseCases {
 public:
    RegisterUC() = default;
    RegisterUC(DataBase* database): database(database) {}

    ErrorStatus addUserToDB(RegisterData user_data);

 private:
    DataBase* database = nullptr;
};


class EditProfileUC: public IServerUseCases {
 public:
    EditProfileUC() = default;
    EditProfileUC(DataBase* database): database(database) {}

    ErrorStatus editUserData(UserData user_data);

 private:
    DataBase* database = nullptr;
};


class DelUserProfileUC: public IServerUseCases {
 public:
    DelUserProfileUC() = default;
    DelUserProfileUC(DataBase* database): database(database) {}

    ErrorStatus delUserData(std::string username);

 private:
    DataBase* database = nullptr;
};


class GetUserProfileUC: public IServerUseCases {
 public:
    GetUserProfileUC() = default;
    GetUserProfileUC(DataBase* database): database(database) {}

    Message<UserData> getUserData(std::string username);

 private:
    DataBase* database = nullptr;
};
