#include "database.hpp"

    
void MainDataBase::connectToDataBase() {

}


bool MainDataBase::InsertIntoPostTable(PostData &data) {
    return true;
}


bool MainDataBase::InsertIntoPersonTable(RegisterData &data) {
    return true;
}


bool MainDataBase::InsertIntoRequestToPostTable(RequestToPostData &data) { 
    return true;
}


bool MainDataBase::DeleteFromPostTable(PostData &data) {
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


bool MainDataBase::EditUserInPersonTable(UserData &data) {
    return true;
}

UserData MainDataBase::getUserProfile(std::string &username) {
    UserData data;
    return data;
}
