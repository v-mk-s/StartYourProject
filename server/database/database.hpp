#pragma once
#include "server_utils.hpp"


class MainDataBase
{
 public:
    explicit MainDataBase() = default;
    
    void connectToDataBase();
    
    bool InsertIntoPostTable(PostData &data);
    bool InsertIntoPersonTable(UserData &data);
    bool InsertIntoRequestToPostTable(RequestToPostData &data);

    bool DeleteFromPostTable(PostData &data);
    bool DeleteFromPersonTable(UserData &data);
    bool DeleteFromRequestToPostTable(RequestToPostData &data);
    bool DeleteFromTable();

    bool FindIntoPersonTable(std::string username);

 private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createPostTable();
    bool createPersonTable();
    bool createRequestToPostTable();
};
