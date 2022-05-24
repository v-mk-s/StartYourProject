#pragma once

#include "dbconnection.hpp"
#include <mysql/mysql.h>

// class MainDataBase
// {
//  public:
//     explicit MainDataBase() = default;
    
//     void connectToDataBase();

//     MySQLQuery* ViewData(UserData *data);

//     virtual bool InsertIntoPostTable(PostData &data);
//     virtual bool InsertIntoPersonTable(RegisterData &data);
//     virtual bool InsertIntoRequestToPostTable(RequestToPostData &data);

//     virtual bool DeleteFromPostTable(PostData &data);
//     virtual bool DeleteFromPersonTable(std::string &data);
//     virtual bool DeleteFromRequestToPostTable(RequestToPostData &data);
//     virtual bool DeleteFromTable();

//     virtual bool EditUserInPersonTable(UserData &data);

//     virtual bool FindIntoPersonTable(LoginData &data);

//     virtual UserData getUserProfile(std::string &username);

//  private:
//     MySQLConnection * sqlConn;
//     bool openDataBase();
//     bool restoreDataBase();
//     void closeDataBase();
//     bool createPostTable();
//     bool createPersonTable();
//     bool createRequestToPostTable();
// };