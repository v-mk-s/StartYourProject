#pragma once

#include "server_utils.hpp"
#include "idatabase.hpp"



class ILoginUC {
 public:
    virtual Message<std::string> checkUser(LoginData& user) = 0;
};

class IRegisterUC {
 public:
    virtual Message<std::string> addUser(RegisterData& user_data) = 0;
};

class IEditProfileUC {
 public:
    virtual Message<std::string> editUserData(UserData& user_data) = 0;
};

class IDelUserProfileUC {
 public:
    virtual Message<std::string> delUserData(int id) = 0;
};

class IGetUserProfileUC {
 public:
    virtual Message<UserData> getUserData(std::string& username) = 0;
};

class IEditPost {
 public:
    virtual ResponseStatus editPostToDB(ProjectData post) = 0;
};

class ISearchPost {
 public:
    virtual Message<ProjectData> makePostSearch(std::string& project_name) = 0;
    virtual Message<std::vector<ProjectData>> makePostSearch(SearchData& data) = 0;
};

class ISearchPerson {
 public:
    virtual Message<UserData> makePersonSearch(std::string& username) = 0;
};

class IMakeRequestToPost {
 public:
    virtual ResponseStatus makeReqToPost(RequestToPostData& request_info) = 0;
};

class IDeletePost {
 public:
    virtual ResponseStatus delPostData(std::string &project_name) = 0;
};

class IAnswerTheRequest {
 public:
    virtual ResponseStatus getAnswer(bool answer, RequestToPostData request_info ) = 0;
};

class IShowNotifications {
 public:
    virtual Message<NotificationData> showAllNotifications(int user_id) = 0;
};

class ICreatePost {
 public:
    virtual ResponseStatus addPostToDB(ProjectData post) = 0;
};


/////////////////////// User UC /////////////////////////////////////

bool checkUsername(std::string& name);
bool checkPassword(std::string& password);
bool checkEmail(std::string& email);

class LoginUC: public ILoginUC {
 public:
    LoginUC() = default;
    LoginUC(IMainDataBase* database): database(database) {}

    Message<std::string> checkUser(LoginData& user);
    std::string generate_token(std::string key);

 private:
    IMainDataBase* database = nullptr;
};


class RegisterUC: public IRegisterUC {
 public:
    RegisterUC() = default;
    RegisterUC(IMainDataBase* database): database(database) {}

    Message<std::string> addUser(RegisterData& user_data);

 private:
    IMainDataBase* database = nullptr;
};


class EditProfileUC: public IEditProfileUC {
 public:
    EditProfileUC() = default;
    EditProfileUC(IMainDataBase* database): database(database) {}

    Message<std::string> editUserData(UserData& user_data);

 private:
    IMainDataBase* database = nullptr;
};


class DelUserProfileUC: public IDelUserProfileUC {
 public:
    DelUserProfileUC() = default;
    DelUserProfileUC(IMainDataBase* database): database(database) {}

    Message<std::string> delUserData(int id);

 private:
    IMainDataBase* database = nullptr;
};


class GetUserProfileUC: public IGetUserProfileUC {
 public:
    GetUserProfileUC() = default;
    GetUserProfileUC(IMainDataBase* database): database(database) {}

    Message<UserData> getUserData(std::string& username);

 private:
    IMainDataBase* database = nullptr;
};


/////////////////////////// Posts UC /////////////////////////////////////

class EditPost{
public:
   EditPost()=default;
   EditPost(IMainDataBase* database): database(database) {}

   ResponseStatus editPostToDB(ProjectData post);
   
private:
   IMainDataBase* database = nullptr;
};

class SearchPost{
public:
   SearchPost()=default;
   SearchPost(IMainDataBase* database): database(database) {}

   Message<ProjectData> makePostSearch(std::string& project_name);
   Message<std::vector<ProjectData>> makeMultiPostSearch(SearchData& data);

private:
   IMainDataBase* database = nullptr;
};

class SearchPerson{
public:
   SearchPerson()=default;
   SearchPerson(IMainDataBase* database): database(database) {}

   Message<UserData> makePersonSearch(std::string& username);

private:
   IMainDataBase* database = nullptr;
};

class MakeRequestToPost{
public:
   MakeRequestToPost()=default;
   MakeRequestToPost(IMainDataBase* database): database(database) {}

   ResponseStatus makeReqToPost(RequestToPostData& request_info);

private:
   IMainDataBase* database = nullptr;
};

class DeletePost{
public:
   DeletePost()=default;
   DeletePost(IMainDataBase* database): database(database) {}
   ResponseStatus delPostData(std::string &project_name);
private:
   IMainDataBase* database = nullptr;
};

class AnswerTheRequest{
public:
   AnswerTheRequest()=default;
   AnswerTheRequest(IMainDataBase* database): database(database) {}
   ResponseStatus getAnswer(bool answer, RequestToPostData request_info);
private:
   IMainDataBase* database = nullptr;
};

class ShowNotifications{
public:
   ShowNotifications()=default;
   ShowNotifications(IMainDataBase* database): database(database) {}
   Message<NotificationData> showAllNotifications(int user_id);
private:
   IMainDataBase* database = nullptr;
};

class CreatePost{
public:
   CreatePost()=default;
   CreatePost(IMainDataBase* database): database(database) {}
   ResponseStatus addPostToDB(ProjectData post);
private:
   IMainDataBase* database = nullptr;
};
