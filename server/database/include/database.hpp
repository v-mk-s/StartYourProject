#pragma once

#include "idatabase.hpp"
#include "server_utils.hpp"

#include <mysql-cppconn-8/mysqlx/xdevapi.h>

#define HOST "127.0.0.1"
#define PORT 33060
#define DB_USER "root"
#define DB_PASSWORD "123qwerty"

#define SYP_DB_NAME "SYP_DB"

#define TAGS_TABLE "tags_data"
#define USER_TABLE "user_data"
#define PROJECT_TABLE "project_data"
#define TEAM_TABLE "team_data"
#define USER_TAGS_TABLE "user_tags_data"
#define TOKEN_TABLE "token_data"
#define NOTIFICATION_TABLE "notification_data"
#define PROJECT_TAGS_TABLE "project_tags_data"



class MainDataBase: public IMainDataBase {
 public:
    MainDataBase() = default;

    // просто добавляют данные и возвращают статус если успешно false иначе true
    DBStatus InsertIntoPostTable(ProjectData &data) override;
    DBStatus InsertIntoUserTable(UserData &data) override;

    DBStatus InsertIntoRequestToPostTable(RequestToPostData &data) override;
    DBStatus InsertIntoTeamTable(std::string &username, std::string &projectname) override;
    
    DBStatus InsertIntoTagsTable(std::string &data) override;
    DBStatus InsertIntoProjectTagsTable(std::string &data, std::string &projectname) override;

    // Удаляют запись и возвращают статус если успешно false иначе true
    DBStatus DeleteFromPostTable(std::string &project_name) override;
    DBStatus DeleteFromPersonTable(std::string &username) override;
    
    DBStatus DeleteFromRequestToPostTable(RequestToPostData &data) override;


    // Изменяют запись и возвращают статус если успешно false иначе true
    DBStatus EditUserInPersonTable(UserData &data) override;
    DBStatus EditPostInPostTable(ProjectData &data) override;
    DBStatus EditRequestToPostTable(RequestToPostData &data) override;

    // Возвращают одну запись
    Message<UserData, DBStatus> FindIntoPersonByUsername(std::string &username) override;
    Message<ProjectData, DBStatus> FindIntoPostTable(std::string &project_name) override;
    
    Message<std::vector<RequestToPostData>, DBStatus>  FindRequestToPostTable(std::string &username) override;
    Message<std::vector<std::string>, DBStatus> FindIntoTeambyProjectName(std::string &project_name) override;
    Message<int, DBStatus> FindTagbyTagName(std::string &tag) override;
    Message<std::string, DBStatus> FindTagbyID(int &id)  override;
    Message<std::vector<std::string>, DBStatus> FindProjectsTags(std::string &project_name) override;

    // Возвращает массив названий проектов которые создал пользователь
    Message<std::vector<std::string>, DBStatus> SearchProjectNames(std::string &username) override;

    DBStatus InsertToken(std::string &username, std::string& token) override;
    // Если токен совпадает то false иначе true
    Message<std::string, DBStatus> FindToken(std::string &username) override;
    DBStatus DeleteToken(std::string &username) override;

    void connect();

    ~MainDataBase();

 private:
    std::unique_ptr<mysqlx::Client> cli;
    std::unique_ptr<mysqlx::Session> sqlconn;
    std::unique_ptr<mysqlx::Schema> db;

    std::unique_ptr<mysqlx::Table> user_data_table;
    std::unique_ptr<mysqlx::Table> project_data_table;
    std::unique_ptr<mysqlx::Table> token_data_table;
    std::unique_ptr<mysqlx::Table> notification_data_table;
    std::unique_ptr<mysqlx::Table> team_data_table;
    std::unique_ptr<mysqlx::Table> user_tags_data_table;
    std::unique_ptr<mysqlx::Table> project_tags_data_table;
    std::unique_ptr<mysqlx::Table> tags_data_table;

    mysqlx::Table CreateTable(const mysqlx::string &name, const mysqlx::string &params);
    void CreateDatabase(std::string db_name);

};

