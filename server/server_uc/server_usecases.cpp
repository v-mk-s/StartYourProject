#include "server_usecases.hpp"


////////////////// User Use Cases /////////////////////////

Message<std::string> LoginUC::checkUser(LoginData& user) {
    if (!database->FindIntoPersonTable(user)) {
        return Message<std::string>(ResponseStatus::not_found, LOGIN_DATA_DONT_MATCH);
    }

    std::string token = generate_token(user.username);
    Message<std::string> msg(ResponseStatus::ok, token);
    return msg;
}

std::string LoginUC::generate_token(std::string key) {
    std::string token = "abc";
    return token;
}


Message<std::string> RegisterUC::addUser(RegisterData& user_data) {
    if (!database->InsertIntoPersonTable(user_data)) {
        return Message<std::string>(ResponseStatus::wrong_data, SAME_USER);
    }
    return Message<std::string>(ResponseStatus::ok);
}


Message<std::string> EditProfileUC::editUserData(UserData& user_data) {
    if (!database->EditUserInPersonTable(user_data)) {
        return Message<std::string>(ResponseStatus::not_found);
    }
    return Message<std::string>(ResponseStatus::ok);
}


Message<std::string> DelUserProfileUC::delUserData(std::string& username) {
    if (!database->DeleteFromPersonTable(username)) {
        return Message<std::string>(ResponseStatus::not_found);
    }
    return Message<std::string>(ResponseStatus::ok);
}


Message<UserData> GetUserProfileUC::getUserData(std::string& username) {
    Message<UserData> msg(ResponseStatus::ok, database->getUserProfile(username));
    return msg;
}


//////////////////// Posts Use Cases ////////////////////////

ResponseStatus EditPost::editPostToDB(PostData post) {
    return ResponseStatus::bad_req;
}


ResponseStatus SearchPost::makePostSearch(PostData post) {
    return ResponseStatus::bad_req;
}


ResponseStatus SearchPerson::makePersonSearch(std::string username) {
    return ResponseStatus::bad_req;
}


ResponseStatus MakeRequestToPost::makeReqToPost(RequestToPostData request_info) {
    return ResponseStatus::bad_req;
}


ResponseStatus DeletePost::delPostData(int post_id) {
    return ResponseStatus::bad_req;
}


ResponseStatus AnswerTheRequest::getAnswer(bool answer, RequestToPostData request_info) {
    return ResponseStatus::bad_req;
}


ResponseStatus ShowNotifications::showAllNotifications(int user_id) {
    return ResponseStatus::bad_req;
}


ResponseStatus CreatePost::addPostToDB(PostData post) {
    return ResponseStatus::bad_req;
}
