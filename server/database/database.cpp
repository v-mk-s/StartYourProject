#include "database.hpp"

    
void MainDataBase::connectToDataBase() {

}


bool MainDataBase::InsertIntoPostTable(ProjectData &data) {
    return true;
}


bool MainDataBase::InsertIntoPersonTable(RegisterData &data) {
    return true;
}


bool MainDataBase::InsertIntoRequestToPostTable(RequestToPostData &data) { 
    return true;
}


bool MainDataBase::DeleteFromPostTable(std::string &project_name) {
    return true;
}


bool MainDataBase::DeleteFromPersonTable(std::string &data) {
    return true;
}


bool MainDataBase::DeleteFromRequestToPostTable(RequestToPostData &data) {
    return true;
}


bool MainDataBase::DeleteFromTable() {
    return true;
}


bool MainDataBase::FindIntoPersonTable(LoginData &data) {
    return true;
}

bool MainDataBase::FindIntoPostTable(std::string &project_name) {
    return true;
}

bool MainDataBase::EditUserInPersonTable(UserData &data) {
    return true;
}

bool MainDataBase::EditPostInPostTable(ProjectData &data) {
    return true;
}

bool MainDataBase::EditRequestToPostTable(RequestToPostData &data) {
    return true;
}

UserData MainDataBase::getUserProfile(std::string &username) {
    UserData data;
    return data;
}

bool MainDataBase::InsertToken(std::string &username, std::string& token) {
    return true;
}

bool MainDataBase::FindToken(std::string &username, std::string& token) {
    return true;
}

NotificationData MainDataBase::FindRequestToPostTable(int &user_id) {
    NotificationData data;
    return data;
}

bool MainDataBase::DeleteToken(std::string &username) {
    return true;
}
std::vector<ProjectData> MainDataBase::getMultiPost(SearchData &data) {
    std::vector<ProjectData> project_data;
    return project_data;
}
ProjectData MainDataBase::getPost(std::string &project_name) {
    ProjectData data;
    return data;
}

