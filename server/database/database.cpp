#include "database.hpp"

    
void MainDataBase::connectToDataBase() {

}


bool MainDataBase::InsertIntoPostTable(PostData &data) {
    return true;
}


bool MainDataBase::InsertIntoPersonTable(UserData &data) {
    return true;
}


bool MainDataBase::InsertIntoRequestToPostTable(RequestToPostData &data) { 
    return true;
}


bool MainDataBase::DeleteFromPostTable(PostData &data) {
    return true;
}


bool MainDataBase::DeleteFromPersonTable(UserData &data) {
    return true;
}


bool MainDataBase::DeleteFromRequestToPostTable(RequestToPostData &data) {
    return true;
}


bool MainDataBase::DeleteFromTable() {
    return true;
}


bool MainDataBase::FindIntoPersonTable(std::string username) {
    return true;
}
