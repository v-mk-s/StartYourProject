#pragma once

#include "server_utils.hpp"



class IMainDataBase
{
 public:
    virtual ~IMainDataBase() = default;

    // просто добавляют данные и возвращают статус если успешно false иначе true
    virtual DBStatus InsertIntoPostTable(ProjectData &data) = 0;
    virtual DBStatus InsertIntoUserTable(UserData &data) = 0;
    virtual DBStatus InsertIntoRequestToPostTable(RequestToPostData &data) = 0;

    // Удаляют запись и возвращают статус если успешно false иначе true
    virtual DBStatus DeleteFromPostTable(std::string &project_name) = 0;
    virtual DBStatus DeleteFromPersonTable(std::string &username) = 0;
    virtual DBStatus DeleteFromRequestToPostTable(RequestToPostData &data) = 0;
    virtual DBStatus DelFromTableNotifications(RequestToPostData& data) = 0;

    // Изменяют запись и возвращают статус если успешно false иначе true
    virtual DBStatus EditUserInPersonTable(UserData &data) = 0;
    virtual DBStatus EditPostInPostTable(ProjectData &data) = 0;
    virtual DBStatus EditRequestToPostTable(RequestToPostData &data) = 0;

    // Возвращают одну запись
    virtual Message<UserData, DBStatus> FindIntoPersonByUsername(std::string &username) = 0;
    virtual Message<ProjectData, DBStatus> FindIntoPostTable(std::string &project_name) = 0;
    virtual Message<std::vector<RequestToPostData>, DBStatus>  FindRequestToPostTable(std::string &username) = 0;

    virtual DBStatus InsertToken(std::string &username, std::string& token) = 0;
    // Если токен совпадает то false иначе true
    virtual Message<std::string, DBStatus> FindToken(std::string &username) = 0;
    virtual DBStatus DeleteToken(std::string &username) = 0;
};
