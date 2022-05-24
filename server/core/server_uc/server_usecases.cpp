#include "server_usecases.hpp"

#define WRONG_NAME "Username is incorrect"
#define WRONG_PASSWORD "Password is incorrect"
#define WRONG_EMAIL "Email is incorrect"
#define LOGIN_DATA_DONT_MATCH "Username and password dont match"
#define SAME_USER "A user with the same name already exists"


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

ResponseStatus EditPost::editPostToDB(ProjectData post) {
    if (!database->EditPostInPostTable(post)) {
        return ResponseStatus::not_found;
    }
    return ResponseStatus::ok;
}


Message<ProjectData> SearchPost::makePostSearch(std::string& project_name) {
    Message<ProjectData> msg(ResponseStatus::ok, database->getPost(project_name));
    return msg;
}

Message<std::vector<ProjectData>> SearchPost::makeMultiPostSearch(SearchData& data) {
    Message<std::vector<ProjectData>> msg(ResponseStatus::ok, database->getMultiPost(data));
    return msg;
}


Message<UserData> SearchPerson::makePersonSearch(std::string& username) {
    Message<UserData> msg(ResponseStatus::ok, database->getUserProfile(username));
    return msg;
}


ResponseStatus MakeRequestToPost::makeReqToPost(RequestToPostData& request_info) {
    if (!database->InsertIntoRequestToPostTable(request_info)) {
        return ResponseStatus::server_error;
    }
    return ResponseStatus::ok;
}


ResponseStatus DeletePost::delPostData(std::string &project_name) {
    if (!database->DeleteFromPostTable(project_name)){
        return ResponseStatus::bad_req;
    } 
    return ResponseStatus::ok;
}


ResponseStatus AnswerTheRequest::getAnswer(bool answer, RequestToPostData request_info) {
    if (answer)
        request_info.status=RequestToPostData::Status::yes;
    else
        request_info.status=RequestToPostData::Status::no;
    if (!database->EditRequestToPostTable(request_info)){
        return ResponseStatus::bad_req;
    } 
    return ResponseStatus::ok;
}


Message<NotificationData> ShowNotifications::showAllNotifications(int user_id) {
    Message<NotificationData> msg(ResponseStatus::ok, database->FindRequestToPostTable(user_id));
    return msg;
}



ResponseStatus CreatePost::addPostToDB(ProjectData post) {
    if (!database->InsertIntoPostTable(post)){
        return ResponseStatus::bad_req;
    } 
    return ResponseStatus::ok;
}


