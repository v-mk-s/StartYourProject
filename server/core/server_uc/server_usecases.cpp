#include "server_usecases.hpp"

#define WRONG_NAME "Username is incorrect"
#define WRONG_PASSWORD "Password is incorrect"
#define WRONG_EMAIL "Email is incorrect"
#define LOGIN_DATA_DONT_MATCH "Username and password dont match"
#define SAME_USER "A user with the same name already exists"
#define SAME_PROJECT "A project with the same name already exists"
#define DB_ERROR "Data base error"


////////////////// User Use Cases /////////////////////////

Message<UserData> LoginUC::checkUser(UserData& user) {
    UserData search_res;
    if(!database->FindIntoPersonByUsername(user.username, search_res)) {
        return Message<UserData>(ResponseStatus::not_found);
    }
    if (search_res.username != user.username || search_res.password != user.password) {
        return Message<UserData>(ResponseStatus::unauthorized, LOGIN_DATA_DONT_MATCH);
    }

    search_res.auth_token = generate_token(user.username + user.password);
    database->InsertToken(search_res.id, search_res.auth_token);

    return Message<UserData>(std::move(search_res));
}

std::string LoginUC::generate_token(std::string key) {
    std::string token = "abc";
    return token;
}


Message<std::string> RegisterUC::addUser(UserData& user_data) {
    UserData search_res;
    if(database->FindIntoPersonByUsername(user_data.username, search_res)) {
        return Message<std::string>(ResponseStatus::forbidden, SAME_USER);
    }
    if (!database->InsertIntoPersonTable(user_data)) {
        return Message<std::string>(ResponseStatus::server_error, DB_ERROR);
    }
    return Message<std::string>(ResponseStatus::ok);
}


Message<std::string> EditProfileUC::editUserData(UserData& user_data) {
    if (!database->CheckToken(user_data.id, user_data.auth_token)) {
        return Message<std::string>(ResponseStatus::unauthorized);
    }
    if (!database->EditUserInPersonTable(user_data)) {
        return Message<std::string>(ResponseStatus::not_found);
    }
    return Message<std::string>(ResponseStatus::ok);
}


Message<std::string> DelUserProfileUC::delUserData(UserData& user_data) {
    if (!database->CheckToken(user_data.id, user_data.auth_token)) {
        return Message<std::string>(ResponseStatus::unauthorized);
    }
    if (!database->DeleteFromPersonTable(user_data.id)) {
        return Message<std::string>(ResponseStatus::not_found);
    }
    return Message<std::string>(ResponseStatus::ok);
}


Message<UserData> GetUserProfileUC::getUserData(std::string& username) {
    UserData data;
    if(!database->FindIntoPersonByUsername(username, data)) {
        return Message<UserData>(ResponseStatus::not_found);
    }
    Message<UserData> msg(ResponseStatus::ok);
    msg.data = data;
    return msg;
}


//////////////////// Posts Use Cases ////////////////////////

ResponseStatus EditPostUC::editPostToDB(ProjectData post, std::string& token) {
    if (!database->CheckToken(post.userid, token)) {
        return ResponseStatus::unauthorized;
    }
    if (!database->EditPostInPostTable(post)) {
        return ResponseStatus::not_found;
    }
    return ResponseStatus::ok;
}


Message<ProjectData> SearchPostUC::makePostSearch(std::string& project_name) {
    ProjectData search_data;
    if (!database->FindIntoPostTable(project_name, search_data)) {
        return Message<ProjectData>(ResponseStatus::not_found);
    }
    Message<ProjectData> msg(ResponseStatus::ok);
    msg.data = search_data;
    return msg;
}

Message<std::vector<ProjectData>> SearchPostUC::makeMultiPostSearch(SearchData& data) {
    Message<std::vector<ProjectData>> msg(ResponseStatus::not_implemented);
    // msg.data = database->getMultiPost(data);
    return msg;
}


Message<UserData> SearchPersonUC::makePersonSearch(std::string& username) {
    Message<UserData> msg(ResponseStatus::not_implemented);
    return msg;
}


ResponseStatus MakeRequestToPostUC::makeReqToPost(RequestToPostData& request_info) {
    // if (!database->InsertIntoRequestToPostTable(request_info)) {
    //     return ResponseStatus::server_error;
    // }
    return ResponseStatus::not_implemented;
}


ResponseStatus DeletePostUC::delPostData(ProjectData& post, std::string& token) {
    if (!database->CheckToken(post.userid, token)) {
        return ResponseStatus::unauthorized;
    }
    if (!database->DeleteFromPostTable(post.projectid)){
        return ResponseStatus::bad_req;
    } 
    return ResponseStatus::ok;
}


ResponseStatus AnswerTheRequestUC::getAnswer(bool answer, RequestToPostData request_info) {
    // if (answer)
    //     request_info.status=RequestToPostData::Status::yes;
    // else
    //     request_info.status=RequestToPostData::Status::no;
    // if (!database->EditRequestToPostTable(request_info)){
    //     return ResponseStatus::bad_req;
    // } 
    return ResponseStatus::not_implemented;
}


Message<NotificationData> ShowNotificationsUC::showAllNotifications(int user_id) {
    Message<NotificationData> msg(ResponseStatus::not_implemented);
    return msg;
}

Message<std::string> CreatePostUC::addPostToDB(ProjectData& post) {
    ProjectData search_data;
    if (database->FindIntoPostTable(post.project_name, search_data)) {
        return Message<std::string>(ResponseStatus::forbidden, SAME_PROJECT);
    }
    if (!database->InsertIntoPostTable(post)){
        return Message<std::string>(ResponseStatus::bad_req);
    } 
    return Message<std::string>(ResponseStatus::ok);
}


