#include "server_usecases.hpp"


////////////////// User Use Cases /////////////////////////

ResponseStatus LoginUC::checkUser(UserData& user) {
    auto msg = database->FindIntoPersonByUsername(user.username);

    if (msg.status == DBStatus::not_found) {
        return ResponseStatus::not_found;
    }
    if (msg.data.username != user.username || msg.data.password != user.password) {
        return ResponseStatus::conflict;
    }
    if (database->FindToken(user.username).status == DBStatus::ok) {
        return ResponseStatus::conflict;
    }

    user.auth_token = generate_token(user.username + user.password);
    if (database->InsertToken(user.username, user.auth_token) != DBStatus::ok) {
        return ResponseStatus::server_error;
    }
    auto project_names = database->SearchProjectNames(user.username);
    if (project_names.status != DBStatus::ok) {
        return ResponseStatus::not_found;
    }
    user.projects = project_names.data;

    return ResponseStatus::ok;
}

std::string LoginUC::generate_token(std::string key) {
    return std::to_string(std::hash<std::string>{}(key));
    
}


ResponseStatus RegisterUC::addUser(UserData& user_data) {
    auto msg = database->FindIntoPersonByUsername(user_data.username);

    if (msg.status == DBStatus::ok || msg.data.username == user_data.username) {
        return ResponseStatus::forbidden;
    }
    if (database->InsertIntoUserTable(user_data) != DBStatus::ok) {
        return ResponseStatus::server_error;
    }
    return ResponseStatus::ok;
}


ResponseStatus EditProfileUC::editUserData(UserData& user_data) {
    auto msg = database->FindToken(user_data.username);
    if (msg.status == DBStatus::not_found || msg.data != user_data.auth_token) {
        return ResponseStatus::unauthorized;
    }
    if (database->EditUserInPersonTable(user_data) != DBStatus::ok) {
        return ResponseStatus::not_found;
    }
    return ResponseStatus::ok;
}


ResponseStatus DelUserProfileUC::delUserData(UserData& user_data) {
    auto msg = database->FindToken(user_data.username);
    if (msg.status == DBStatus::not_found || msg.data != user_data.auth_token) {
        return ResponseStatus::unauthorized;
    }
    if (database->DeleteFromPersonTable(user_data.username) != DBStatus::ok) {
        return ResponseStatus::not_found;
    }
    if (database->DeleteToken(user_data.username) != DBStatus::ok) {
        return ResponseStatus::server_error;
    }
    return ResponseStatus::ok;
}


Message<UserData> GetUserProfileUC::getUserData(std::string& username) {
    auto msg = database->FindIntoPersonByUsername(username);

    if (msg.status == DBStatus::not_found) {
        return Message<UserData>(ResponseStatus::not_found);
    }
    return Message<UserData>(std::move(msg.data));
}


//////////////////// Posts Use Cases ////////////////////////

ResponseStatus CreatePostUC::addPostToDB(ProjectData& post, std::string& token) {
    auto token_msg = database->FindToken(post.username);
    if (token_msg.status == DBStatus::not_found || token_msg.data != token) {
        return ResponseStatus::unauthorized;
    }
    auto msg = database->FindIntoPostTable(post.project_name);
    if (msg.status == DBStatus::ok || msg.data.project_name == post.project_name) {
        return ResponseStatus::forbidden;
    }
    if (database->InsertIntoPostTable(post) != DBStatus::ok){
        return ResponseStatus::server_error;
    }
    return ResponseStatus::ok;
}


ResponseStatus EditPostUC::editPostToDB(ProjectData post, std::string& token) {
    auto msg = database->FindToken(post.username);
    if (msg.status == DBStatus::not_found || msg.data != token) {
        return ResponseStatus::unauthorized;
    }
    if (database->EditPostInPostTable(post) == DBStatus::not_found) {
        return ResponseStatus::not_found;
    }
    return ResponseStatus::ok;
}


Message<ProjectData> GetPostUC::getPost(std::string& project_name) {
    auto msg = database->FindIntoPostTable(project_name);

    if (msg.status == DBStatus::not_found) {
        return Message<ProjectData>(ResponseStatus::not_found);
    }
    return Message<ProjectData>(std::move(msg.data));
}


ResponseStatus DeletePostUC::delPostData(ProjectData& post, std::string& token) {
    auto msg = database->FindToken(post.username);
    if (msg.status == DBStatus::not_found || msg.data != token) {
        return ResponseStatus::unauthorized;
    }
    if (database->DeleteFromPostTable(post.project_name) != DBStatus::ok){
        return ResponseStatus::not_found;
    }
    return ResponseStatus::ok;
}


ResponseStatus MakeRequestToPostUC::makeReqToPost(RequestToPostData& request_info) {
    return ResponseStatus::not_implemented;
}


ResponseStatus AnswerTheRequestUC::getAnswer(bool answer, RequestToPostData request_info) {
    return ResponseStatus::not_implemented;
}


ResponseStatus ShowNotificationsUC::showAllNotifications(int user_id) {
    return ResponseStatus::not_implemented;
}

Message<UserData> SearchPersonUC::makePersonSearch(std::string& username) {
    return Message<UserData>(ResponseStatus::not_implemented);
}

