#pragma once
#include "server_utils.hpp"


class MainDataBase
{
 public:
    explicit MainDataBase() = default;
    
    void connectToDataBase();

    virtual bool InsertIntoPostTable(ProjectData &data);
    virtual bool InsertIntoPersonTable(RegisterData &data);
    virtual bool InsertIntoRequestToPostTable(RequestToPostData &data);

    virtual bool DeleteFromPostTable(std::string &project_name);
    virtual bool DeleteFromPersonTable(std::string &data);
    virtual bool DeleteFromRequestToPostTable(RequestToPostData &data);
    virtual bool DeleteFromTable();

    virtual bool EditUserInPersonTable(UserData &data);
    virtual bool EditPostInPostTable(ProjectData &data);
    virtual bool EditRequestToPostTable(RequestToPostData &data);


    virtual bool FindIntoPersonTable(LoginData &data);
    virtual bool FindIntoPostTable(std::string &project_name);
    virtual NotificationData FindRequestToPostTable(int &user_id);

    virtual bool InsertToken(std::string &username, std::string& token);
    virtual bool FindToken(std::string &username, std::string& token);
    virtual bool DeleteToken(std::string &username);

    virtual UserData getUserProfile(std::string &username);
    virtual ProjectData getPost(std::string &project_name);
    virtual std::vector<ProjectData> getMultiPost(SearchData &data);

 private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createPostTable();
    bool createPersonTable();
    bool createRequestToPostTable();
};
