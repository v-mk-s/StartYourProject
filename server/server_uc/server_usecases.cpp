#include "server_usecases.hpp"


////////////////// User Use Cases /////////////////////////

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


//////////////////// Posts Use Cases ////////////////////////

ErrorStatus EditPost::editPostToDB(PostData post) {
    return ErrorStatus::unnown;
}


ErrorStatus SearchPost::makePostSearch(PostData post) {
    return ErrorStatus::unnown;
}


ErrorStatus SearchPerson::makePersonSearch(std::string username) {
    return ErrorStatus::unnown;
}


ErrorStatus MakeRequestToPost::makeReqToPost(RequestToPostData request_info) {
    return ErrorStatus::unnown;
}


ErrorStatus DeletePost::delPostData(int post_id) {
    return ErrorStatus::unnown;
}


ErrorStatus AnswerTheRequest::getAnswer(bool answer, RequestToPostData request_info) {
    return ErrorStatus::unnown;
}


ErrorStatus ShowNotifications::showAllNotifications(int user_id) {
    return ErrorStatus::unnown;
}


ErrorStatus CreatePost::addPostToDB(PostData post) {
    return ErrorStatus::unnown;
}
