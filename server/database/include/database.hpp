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

    // просто добавляют данные и возвращают статус если успешно false иначе true
    DBStatus InsertIntoPostTable(ProjectData &data) override;
    DBStatus InsertIntoUserTable(UserData &data) override;
    DBStatus InsertIntoRequestToPostTable(RequestToPostData &data) override;

    // Удаляют запись и возвращают статус если успешно false иначе true
    DBStatus DeleteFromPostTable(std::string &project_name) override;
    DBStatus DeleteFromPersonTable(std::string &username) override;
    DBStatus DeleteFromRequestToPostTable(RequestToPostData &data) override;
    DBStatus DelFromTableNotifications(RequestToPostData& data) override;

    // Изменяют запись и возвращают статус если успешно false иначе true
    DBStatus EditUserInPersonTable(UserData &data) override;
    DBStatus EditPostInPostTable(ProjectData &data) override;
    DBStatus EditRequestToPostTable(RequestToPostData &data) override;

    // Возвращают одну запись
    Message<UserData, DBStatus> FindIntoPersonByUsername(std::string &username) override;
    Message<ProjectData, DBStatus> FindIntoPostTable(std::string &project_name) override;
    Message<std::vector<RequestToPostData>, DBStatus>  FindRequestToPostTable(std::string &username) override;

    DBStatus InsertToken(std::string &username, std::string& token) override;
    // Если токен совпадает то false иначе true
    bool CheckToken(std::string &username, std::string& token) override;
    DBStatus DeleteToken(std::string &username) override;

    ~MainDataBase();

 private:

    mysqlx::Session sqlconn;
    mysqlx::Schema db;
    mysqlx::Table user_data_table;
    mysqlx::Table project_data_table;
    mysqlx::Table token_data_table;
    mysqlx::Table notification_data_table;
};
