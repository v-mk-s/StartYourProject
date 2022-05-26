#pragma once

#include "idatabase.hpp"
#include "server_utils.hpp"
#include "dbconnection.hpp"

// fake
#include <map>


class MainDataBase: public IMainDataBase 
{
 public:
    // MainDataBase() = default;
    MainDataBase(MySQLConnection *sqlconn_);

    bool InsertIntoPostTable(ProjectData &data);
    bool InsertIntoPersonTable(RegisterData &data);
    bool InsertIntoRequestToPostTable(RequestToPostData &data);

    bool DeleteFromPostTable(int id);
    bool DeleteFromPersonTable(int id);
    bool DeleteFromRequestToPostTable(RequestToPostData &data);
    bool DelFromTableToken(int id);
    bool DelFromTableNotifications(RequestToPostData& data);

    bool EditUserInPersonTable(UserData &data);
    bool EditPostInPostTable(ProjectData &data);
    bool EditRequestToPostTable(RequestToPostData &data);


    bool FindIntoPersonTable(LoginData &data);
    UserData FindIntoPersonByUsername(std::string &username);
    UserData FindIntoPersonByID(int &id);
    bool FindIntoPostTable(std::string &project_name);
    NotificationData FindRequestToPostTable(int &user_id);

    bool InsertToken(std::string &username, std::string& token);
    bool FindToken(std::string &username, std::string& token);
    bool DeleteToken(std::string &username);

    UserData getUserProfile(std::string &username);
    ProjectData getPost(std::string &project_name);
    std::vector<ProjectData> getMultiPost(SearchData &data);

    std::vector<RequestToPostData> SelectNotifications(int &user_id);
    ProjectData SelectPostByID(int &id);

    ~MainDataBase() = default;

 private:
    MySQLConnection *sqlconn;

    // fake bd
    std::unordered_map<int, std::vector<std::string>> table_;

    bool add_record(int id, const std::vector<std::string>& record);
    bool delete_record(int id);
    bool find_record(int id);
    std::vector<std::string> get_record(int id);
};
