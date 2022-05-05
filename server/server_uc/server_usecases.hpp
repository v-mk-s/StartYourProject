#pragma once

#include "server_utils.hpp"
#include "database.hpp"
#include <regex>

#define WRONG_NAME "Username is incorrect"
#define WRONG_PASSWORD "Password is incorrect"
#define WRONG_EMAIL "Email is incorrect"
#define LOGIN_DATA_DONT_MATCH "Username and password dont match"
#define SAME_USER "A user with the same name already exists"


class IServerUseCases {
 public:
    // virtual ErrorStatus checkUser(LoginData) = 0;
    // virtual ErrorStatus addUser(RegisterData) = 0;
    // virtual ErrorStatus editUserData(UserData) = 0;
    // virtual ErrorStatus delUserData(std::string) = 0;
    // virtual Message<UserData> getUserData(std::string) = 0;
    // virtual ErrorStatus editPostToDB(PostData post) = 0;
    // virtual ErrorStatus makePostSearch(PostData post) = 0;
    // virtual ErrorStatus makePersonSearch(std::string username) = 0;
    // virtual ErrorStatus makeReqToPost(RequestToPostData request_info) = 0;
    // virtual ErrorStatus delPostData(int post_id) = 0;
    // virtual ErrorStatus getAnswer(bool answer, RequestToPostData request_info ) = 0;
    // virtual ErrorStatus showAllNotifications(int user_id) = 0;
    // virtual ErrorStatus addPostToDB(PostData post) = 0;
};


/////////////////////// User UC /////////////////////////////////////

bool checkUsername(std::string& name);
bool checkPassword(std::string& password);
bool checkEmail(std::string& email);


class LoginUC: public IServerUseCases {
 public:
    LoginUC() = default;
    LoginUC(MainDataBase* database): database(database) {}

    Message<std::string> checkUser(LoginData user);
    std::string generate_token(std::string key);

 private:
    MainDataBase* database = nullptr;
};


class RegisterUC: public IServerUseCases {
 public:
    RegisterUC() = default;
    RegisterUC(MainDataBase* database): database(database) {}

    Message<std::string> addUser(RegisterData user_data);

 private:
    MainDataBase* database = nullptr;
};


class EditProfileUC: public IServerUseCases {
 public:
    EditProfileUC() = default;
    EditProfileUC(MainDataBase* database): database(database) {}

    Message<std::string> editUserData(UserData user_data);

 private:
    MainDataBase* database = nullptr;
};


class DelUserProfileUC: public IServerUseCases {
 public:
    DelUserProfileUC() = default;
    DelUserProfileUC(MainDataBase* database): database(database) {}

    Message<std::string> delUserData(std::string username);

 private:
    MainDataBase* database = nullptr;
};


class GetUserProfileUC: public IServerUseCases {
 public:
    GetUserProfileUC() = default;
    GetUserProfileUC(MainDataBase* database): database(database) {}

    Message<UserData> getUserData(std::string username);

 private:
    MainDataBase* database = nullptr;
};


/////////////////////////// Posts UC /////////////////////////////////////

class EditPost{
public:
   EditPost()=default;
   EditPost(MainDataBase* database): database(database) {}
   ErrorStatus editPostToDB(PostData post);
private:
   MainDataBase* database = nullptr;
};

class SearchPost{
public:
   SearchPost()=default;
   SearchPost(MainDataBase* database): database(database) {}
   ErrorStatus makePostSearch(PostData post);
private:
   MainDataBase* database = nullptr;
};

class SearchPerson{
public:
   SearchPerson()=default;
   SearchPerson(MainDataBase* database): database(database) {}
   ErrorStatus makePersonSearch(std::string username);
private:
   MainDataBase* database = nullptr;
};

class MakeRequestToPost{
public:
   MakeRequestToPost()=default;
   MakeRequestToPost(MainDataBase* database): database(database) {}
   ErrorStatus makeReqToPost(RequestToPostData request_info);
private:
   MainDataBase* database = nullptr;
};

class DeletePost{
public:
   DeletePost()=default;
   DeletePost(MainDataBase* database): database(database) {}
   ErrorStatus delPostData(int post_id);
private:
   MainDataBase* database = nullptr;
};

class AnswerTheRequest{
public:
   AnswerTheRequest()=default;
   AnswerTheRequest(MainDataBase* database): database(database) {}
   ErrorStatus getAnswer(bool answer, RequestToPostData request_info);
private:
   MainDataBase* database = nullptr;
};

class ShowNotifications{
public:
   ShowNotifications()=default;
   ShowNotifications(MainDataBase* database): database(database) {}
   ErrorStatus showAllNotifications(int user_id);
private:
   MainDataBase* database = nullptr;
};

class CreatePost{
public:
   CreatePost()=default;
   CreatePost(MainDataBase* database): database(database) {}
   ErrorStatus addPostToDB(PostData post);
private:
   MainDataBase* database = nullptr;
};
