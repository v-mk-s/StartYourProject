#pragma once

#include "server_utils.hpp"



class IMainDataBase
{
 public:
    virtual ~IMainDataBase() = default;

    virtual bool InsertIntoPostTable(ProjectData &data) = 0;
    virtual bool InsertIntoUserTable(UserData &data) = 0;
    virtual bool InsertIntoRequestToPostTable(RequestToPostData &data) = 0;

    virtual bool DeleteFromPostTable(std::string &project_name) = 0;
    virtual bool DeleteFromPersonTable(int id) = 0;
    virtual bool DeleteFromRequestToPostTable(RequestToPostData &data) = 0;
    virtual bool DelFromTableNotifications(RequestToPostData& data) = 0;

    virtual bool EditUserInPersonTable(UserData &data) = 0;
    virtual bool EditPostInPostTable(ProjectData &data) = 0;
    virtual bool EditRequestToPostTable(RequestToPostData &data) = 0;

    // virtual bool FindIntoPersonTable(LoginData &data) = 0;
    // virtual bool FindIntoPersonByUsername(std::string &username, UserData& data) = 0;
    // virtual bool FindIntoPersonByID(int &id) = 0;
    // virtual bool FindIntoPostTable(std::string &project_name, ProjectData& data) = 0;
    // virtual NotificationData FindRequestToPostTable(int &user_id) = 0;

    virtual UserData FindIntoPersonByID(int id) = 0;
    virtual UserData FindIntoPersonByUsername(std::string &username) = 0;
    virtual bool FindIntoPostTable(std::string &project_name) = 0;
    virtual std::vector<RequestToPostData> FindRequestToPostTable(int &user_id) = 0;
    virtual ProjectData SelectPostByID(int &id)=0;
    virtual ProjectData SelectPostByProjectname(std::string &project_name) = 0;


    virtual bool InsertToken(std::string &username, std::string& token) = 0;
    virtual bool CheckToken(std::string &username, std::string& token) = 0;
    virtual bool DeleteToken(std::string &username) = 0;

    // virtual UserData getUserProfile(std::string &username) = 0;
    // virtual ProjectData getPost(std::string &project_name) = 0;
    // virtual std::vector<ProjectData> getMultiPost(SearchData &data) = 0;

    virtual std::vector<RequestToPostData> SelectNotifications(int &user_id) = 0;
    // virtual ProjectData SelectPostByID(int &id) = 0;
    // virtual bool IsUnique(std::string &username) = 0;

    // private:
    // Session sqlconn;
    // Schema db;
    // var   user_data_table;
    // var   project_data_table;
    // var   token_data_table;
    // var   notification_data_table;
};
