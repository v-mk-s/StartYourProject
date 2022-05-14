#include "server_usecases.hpp"


////////////////// User Use Cases /////////////////////////

Message<std::string> LoginUC::checkUser(LoginData& user) {
    if (!database->FindIntoPersonTable(user)) {
        return Message<std::string>(ErrorStatus::not_found, LOGIN_DATA_DONT_MATCH);
    }

    std::string token = generate_token(user.username);
    Message<std::string> msg(ErrorStatus::ok, token);
    return msg;
}

std::string LoginUC::generate_token(std::string key) {
    std::string token = "abc";
    return token;
}


Message<std::string> RegisterUC::addUser(RegisterData& user_data) {
    if (!database->InsertIntoPersonTable(user_data)) {
        return Message<std::string>(ErrorStatus::wrong_data, SAME_USER);
    }
    return Message<std::string>(ErrorStatus::ok);
}


Message<std::string> EditProfileUC::editUserData(UserData& user_data) {
    if (!database->EditUserInPersonTable(user_data)) {
        return Message<std::string>(ErrorStatus::not_found);
    }
    return Message<std::string>(ErrorStatus::ok);
}


Message<std::string> DelUserProfileUC::delUserData(std::string& username) {
    if (!database->DeleteFromPersonTable(username)) {
        return Message<std::string>(ErrorStatus::not_found);
    }
    return Message<std::string>(ErrorStatus::ok);
}


Message<UserData> GetUserProfileUC::getUserData(std::string& username) {
    Message<UserData> msg(ErrorStatus::ok, database->getUserProfile(username));
    return msg;
}


//////////////////// Posts Use Cases ////////////////////////

ErrorStatus EditPost::editPostToDB(PostData post) {
    return ErrorStatus::bad_req;
}


ErrorStatus SearchPost::makePostSearch(PostData post) {
    return ErrorStatus::bad_req;
}


ErrorStatus SearchPerson::makePersonSearch(std::string username) {
    return ErrorStatus::bad_req;
}


ErrorStatus MakeRequestToPost::makeReqToPost(RequestToPostData request_info) {
    return ErrorStatus::bad_req;
}


ErrorStatus DeletePost::delPostData(int post_id) {
    return ErrorStatus::bad_req;
}


ErrorStatus AnswerTheRequest::getAnswer(bool answer, RequestToPostData request_info) {
    return ErrorStatus::bad_req;
}


ErrorStatus ShowNotifications::showAllNotifications(int user_id) {
    return ErrorStatus::bad_req;
}


ErrorStatus CreatePost::addPostToDB(PostData post) {
    return ErrorStatus::bad_req;
}
