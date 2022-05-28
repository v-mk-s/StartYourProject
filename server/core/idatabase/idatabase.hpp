#pragma once
#include "server_utils.hpp"
#include <mysql-cppconn-8/mysqlx/xdevapi.h>




class MainDataBase
{
 public:
    MainDataBase();
    ~MainDataBase();
    virtual bool InsertIntoPostTable(ProjectData &data) = 0;
    virtual bool InsertIntoUserTable(RegisterData &data) = 0;
    virtual bool InsertIntoRequestToPostTable(RequestToPostData &data) = 0;


    virtual bool DeleteFromPostTable(std::string &project_name) = 0;
    virtual bool DeleteFromPersonTable(std::string  &username) = 0;
    virtual bool DeleteFromRequestToPostTable(RequestToPostData &data) = 0;


    virtual bool EditUserInPersonTable(UserData &data) = 0;
    virtual bool EditPostInPostTable(ProjectData &data) = 0;
    virtual bool EditRequestToPostTable(RequestToPostData &data) = 0;


    virtual UserData FindIntoPersonByID(int &id) = 0;
    virtual bool FindIntoPostTable(std::string &project_name) = 0;
    virtual std::vector<RequestToPostData> FindRequestToPostTable(int &user_id) = 0;
    virtual UserData FindIntoPersonByUsername(std::string &username) = 0;
    virtual ProjectData SelectPostByID(int &id)=0;
    virtual ProjectData SelectPostByProjectname(std::string &project_name)=0;


    virtual bool InsertToken(std::string &username, std::string& token) = 0;
    virtual bool FindToken(std::string &username, std::string& token) = 0;
    virtual bool DeleteToken(std::string &username) = 0;

    virtual UserData getUserProfile(std::string &username) = 0;
    virtual ProjectData getPost(std::string &project_name) = 0;
    virtual std::vector<ProjectData> getMultiPost(SearchData &data) = 0;
    virtual bool IsUnique(std::string &username)=0;
    private:
    mysqlx::Session sqlconn;
    mysqlx::Schema db;
    mysqlx::Table   user_data_table;
    mysqlx::Table   project_data_table;
    mysqlx::Table   token_data_table;
    mysqlx::Table   notification_data_table;
};
