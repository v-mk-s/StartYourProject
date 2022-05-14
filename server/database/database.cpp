#include "database.hpp"

    
void MainDataBase::connectToDataBase() {

this->sqlConn = new MySQLConnection();
sqlConn->Connect("localhost", 3306, "root", "password", "ProjectData");
}


MySQLQuery * MainDataBase::ViewData(UserData* data){
    MySQLQuery * view = new MySQLQuery(this->sqlConn, "SELECT username, email, password, name, sur_name, user_description from userdata where username like %" + data->username +"%;" );
    return view;
}


bool MainDataBase::InsertIntoPostTable(PostData &data) {
    return true;
}


bool MainDataBase::InsertIntoPersonTable(RegisterData &data) {
    MySQLQuery * insertq = new MySQLQuery(this->sqlConn, "INSERT INTO userdata (username, email, password) VALUES "+data.username+" "+data.email+" "+data.password +";");
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
