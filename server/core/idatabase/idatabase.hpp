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
    
    virtual DBStatus InsertIntoTagsTable(std::string &data) = 0;
    virtual DBStatus InsertIntoProjectTagsTable(std::string &data, std::string &project_name) = 0;
    virtual DBStatus InsertIntoTeamTable(std::string &username, std::string &projectname) = 0;
    // Удаляют запись и возвращают статус если успешно false иначе true
    virtual DBStatus DeleteFromPostTable(std::string &project_name) = 0;
    virtual DBStatus DeleteFromPersonTable(std::string &username) = 0;
    
    virtual DBStatus DeleteFromRequestToPostTable(RequestToPostData &data) = 0;


    // Изменяют запись и возвращают статус если успешно false иначе true
    virtual DBStatus EditUserInPersonTable(UserData &data) = 0;
    virtual DBStatus EditPostInPostTable(ProjectData &data) = 0;

    virtual DBStatus EditRequestToPostTable(RequestToPostData &data) = 0;

    // Возвращают одну запись
    virtual Message<UserData, DBStatus> FindIntoPersonByUsername(std::string &username) = 0;
    virtual Message<ProjectData, DBStatus> FindIntoPostTable(std::string &project_name) = 0;

    virtual Message<std::vector<RequestToPostData>, DBStatus>  FindRequestToPostTable(std::string &username) = 0;
    virtual Message<std::vector<std::string>, DBStatus> FindIntoTeambyProjectName(std::string &project_name) = 0;
    virtual Message<int, DBStatus> FindTagbyTagName(std::string &tag) = 0;
    virtual Message<std::string, DBStatus> FindTagbyID(int &id) = 0;
    virtual Message<std::vector<std::string>, DBStatus> FindProjectsTags(std::string &project_name) = 0;
 
    // Возвращает массив названий проектов которые создал пользователь
    virtual Message<std::vector<std::string>, DBStatus> SearchProjectNames(std::string &username) = 0;
    virtual Message<std::vector<ProjectData>, DBStatus> SearchProjects(std::string &search_string) =0;
    virtual DBStatus InsertToken(std::string &username, std::string& token) = 0;
    // Если токен совпадает то false иначе true
    virtual Message<std::string, DBStatus> FindToken(std::string &username) = 0;
    virtual DBStatus DeleteToken(std::string &username) = 0;
};
