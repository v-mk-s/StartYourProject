#pragma once

#include "server_utils.hpp"
#include "idatabase.hpp"



class ILoginUC {
 public:
    virtual Message<UserData> checkUser(UserData& user) = 0;
};

class IRegisterUC {
 public:
    virtual Message<std::string> addUser(UserData& user_data) = 0;
};

class IEditProfileUC {
 public:
    virtual Message<std::string> editUserData(UserData& user_data) = 0;
};

class IDelUserProfileUC {
 public:
    virtual Message<std::string> delUserData(UserData& user_data) = 0;
};

class IGetUserProfileUC {
 public:
    virtual Message<UserData> getUserData(std::string& username) = 0;
};

class IEditPostUC {
 public:
    virtual ResponseStatus editPostToDB(ProjectData post, std::string& token) = 0;
};

class ISearchPostUC {
 public:
    virtual Message<ProjectData> makePostSearch(std::string& project_name) = 0;
    virtual Message<std::vector<ProjectData>> makeMultiPostSearch(SearchData& data) = 0;
};

class ISearchPersonUC {
 public:
    virtual Message<UserData> makePersonSearch(std::string& username) = 0;
};

class IMakeRequestToPostUC {
 public:
    virtual ResponseStatus makeReqToPost(RequestToPostData& request_info) = 0;
};

class IDeletePostUC {
 public:
    virtual ResponseStatus delPostData(ProjectData& post, std::string& token) = 0;
};

class IAnswerTheRequestUC {
 public:
    virtual ResponseStatus getAnswer(bool answer, RequestToPostData request_info ) = 0;
};

class IShowNotificationsUC {
 public:
    virtual Message<NotificationData> showAllNotifications(int user_id) = 0;
};

class ICreatePostUC {
 public:
    virtual Message<std::string> addPostToDB(ProjectData& post) = 0;
};


/////////////////////// User UC /////////////////////////////////////


class LoginUC: public ILoginUC {
 public:
    LoginUC() = delete;
    LoginUC(IMainDataBase* database): database(database) {}

    Message<UserData> checkUser(UserData& user) override;
    std::string generate_token(std::string& key);

 private:
    IMainDataBase* database;
};


class RegisterUC: public IRegisterUC {
 public:
    RegisterUC() = delete;
    RegisterUC(IMainDataBase* database): database(database) {}

    Message<std::string> addUser(UserData& user_data) override;

 private:
    IMainDataBase* database;
};


class EditProfileUC: public IEditProfileUC {
 public:
    EditProfileUC() = delete;
    EditProfileUC(IMainDataBase* database): database(database) {}

    Message<std::string> editUserData(UserData& user_data) override;

 private:
    IMainDataBase* database;
};


class DelUserProfileUC: public IDelUserProfileUC {
 public:
    DelUserProfileUC() = delete;
    DelUserProfileUC(IMainDataBase* database): database(database) {}

    Message<std::string> delUserData(UserData& user_data) override;

 private:
    IMainDataBase* database;
};


class GetUserProfileUC: public IGetUserProfileUC {
 public:
    GetUserProfileUC() = delete;
    GetUserProfileUC(IMainDataBase* database): database(database) {}

    Message<UserData> getUserData(std::string& username) override;

 private:
    IMainDataBase* database;
};


/////////////////////////// Posts UC /////////////////////////////////////

class EditPostUC: public IEditPostUC {
 public:
    EditPostUC() = delete;
    EditPostUC(IMainDataBase* database): database(database) {}

    ResponseStatus editPostToDB(ProjectData post, std::string& token) override;
    
 private:
    IMainDataBase* database;
};

class SearchPostUC: public ISearchPostUC {
 public:
    SearchPostUC() = delete;
    SearchPostUC(IMainDataBase* database): database(database) {}

    Message<ProjectData> makePostSearch(std::string& project_name) override;
    Message<std::vector<ProjectData>> makeMultiPostSearch(SearchData& data) override;

 private:
    IMainDataBase* database;
};

class SearchPersonUC: public ISearchPersonUC {
 public:
    SearchPersonUC() = delete;
    SearchPersonUC(IMainDataBase* database): database(database) {}

    Message<UserData> makePersonSearch(std::string& username) override;

 private:
    IMainDataBase* database;
};

class MakeRequestToPostUC: public IMakeRequestToPostUC {
 public:
    MakeRequestToPostUC() = delete;
    MakeRequestToPostUC(IMainDataBase* database): database(database) {}

    ResponseStatus makeReqToPost(RequestToPostData& request_info) override;

 private:
    IMainDataBase* database;
};

class DeletePostUC: public IDeletePostUC {
 public:
    DeletePostUC() = delete;
    DeletePostUC(IMainDataBase* database): database(database) {}
    
    ResponseStatus delPostData(ProjectData& post, std::string& token) override;

 private:
    IMainDataBase* database;
};

class AnswerTheRequestUC: public IAnswerTheRequestUC {
 public:
    AnswerTheRequestUC() = delete;
    AnswerTheRequestUC(IMainDataBase* database): database(database) {}

    ResponseStatus getAnswer(bool answer, RequestToPostData request_info) override;

 private:
    IMainDataBase* database;
};

class ShowNotificationsUC: public IShowNotificationsUC {
 public:
    ShowNotificationsUC() = delete;
    ShowNotificationsUC(IMainDataBase* database): database(database) {}

    Message<NotificationData> showAllNotifications(int user_id) override;
    
 private:
    IMainDataBase* database;
};

class CreatePostUC: public ICreatePostUC {
 public:
    CreatePostUC() = delete;
    CreatePostUC(IMainDataBase* database): database(database) {}

    Message<std::string> addPostToDB(ProjectData& post) override;

 private:
    IMainDataBase* database;
};
