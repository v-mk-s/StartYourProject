#pragma once

#include "utils.hpp"


// class ServerUseCases {
//  public:
//     ServerUseCases();
// };


class LoginUC {
 public:
    Response checkUserInDB(LoginData user);
};


class RegisterUC {
 public:
    Response addUserToDB(RegisterData user_data);
};


class EditProfileUC {
 public:
    Response editUserData(UserData user_data);
};


class DelUserProfileUC {
 public:
    Response delUserData(std::string username);
};
