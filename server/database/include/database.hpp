#pragma once

#include "idatabase.hpp"
#include "server_utils.hpp"

#include <mysql-cppconn-8/mysqlx/xdevapi.h>

#define HOST "127.0.0.1"
#define PORT 33060
#define DB_USER "root"
#define DB_PASSWORD "123qwerty"

// fake
#include <unordered_map>


class MainDataBase: public IMainDataBase 
{
 public:
    MainDataBase();
    // MainDataBase(MySQLConnection *sqlconn_);

    bool InsertIntoPostTable(ProjectData &data) override;
    bool InsertIntoUserTable(UserData &data) override;
    bool InsertIntoRequestToPostTable(RequestToPostData &data) override;

    bool DeleteFromPostTable(std::string &project_name) override;
    bool DeleteFromPersonTable(int id) override;
    bool DeleteFromRequestToPostTable(RequestToPostData &data) override;
    // bool DelFromTableToken(int id) override;
    bool DelFromTableNotifications(RequestToPostData& data) override;

    bool EditUserInPersonTable(UserData &data) override;
    bool EditPostInPostTable(ProjectData &data) override;
    bool EditRequestToPostTable(RequestToPostData &data) override;


    UserData FindIntoPersonByUsername(std::string &username) override;
    UserData FindIntoPersonByID(int id) override;
    bool FindIntoPostTable(std::string &project_name) override;
    std::vector<RequestToPostData> FindRequestToPostTable(int &user_id) override;
    ProjectData SelectPostByProjectname(std::string &project_name) override;

    bool InsertToken(std::string &username, std::string& token) override;
    bool CheckToken(std::string &username, std::string& token) override;
    bool DeleteToken(std::string &username) override;

    // UserData getUserProfile(std::string &username) override;
    // ProjectData getPost(std::string &project_name) override;
   //  std::vector<ProjectData> getMultiPost(SearchData &data) override;

    std::vector<RequestToPostData> SelectNotifications(int &user_id) override;
    ProjectData SelectPostByID(int &id);

   //  bool IsUnique(std::string &username) override;

    ~MainDataBase();

 private:

    mysqlx::Session sqlconn;
    mysqlx::Schema db;
    mysqlx::Table user_data_table;
    mysqlx::Table project_data_table;
    mysqlx::Table token_data_table;
    mysqlx::Table notification_data_table;

    // fake bd
    // std::unordered_map<int, std::vector<std::string>> table_;

    // bool add_record(int id, const std::vector<std::string>& record);
    // bool delete_record(int id);
    // bool find_record(int id);
    // std::vector<std::string> get_record(int id);
};
