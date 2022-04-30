#include "server_usecases.hpp"


ErrorStatus LoginUC::checkUserInDB(LoginData user) {
    user;
    return ErrorStatus::unnown;
}


ErrorStatus RegisterUC::addUserToDB(RegisterData user_data) {
    user_data;
    return ErrorStatus::unnown;
}


ErrorStatus EditProfileUC::editUserData(UserData user_data) {
    user_data;
    return ErrorStatus::unnown;
}


ErrorStatus DelUserProfileUC::delUserData(std::string username) {
    username:
    return ErrorStatus::unnown;
}


Message<UserData> GetUserProfileUC::getUserData(std::string username) {
    username;
    return Message<UserData>();
}