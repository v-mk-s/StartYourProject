#pragma once

#include "utils.h"


class IServerUseCases {
 public:
    virtual ErrorStatus editPostToDB(PostData post) = 0;
    virtual ErrorStatus makePostSearch(PostData post) = 0;
    virtual ErrorStatus makePersonSearch(std::string username) = 0;
    virtual ErrorStatus makeReqToPost(RequestToPostData request_info) = 0;
    virtual ErrorStatus delPostData(int post_id) = 0;
    virtual ErrorStatus getAnswer(bool answer, RequestToPostData request_info ) = 0;
    virtual ErrorStatus showAllNotifications(int user_id) = 0;
    virtual ErrorStatus addPostToDB(PostData post) = 0;
};




class EditPost{
public:
   EditPost()=default;
   EditPost(DataBase* database): database(database) {}
   ErrorStatus editPostToDB(PostData post);
private:
   DataBase* database = nullptr;
}

class SearchPost{
public:
   SearchPost()=default;
   SearchPost(DataBase* database): database(database) {}
   ErrorStatus makePostSearch(PostData post);
private:
   DataBase* database = nullptr;
}

class SearchPerson{
public:
   SearchPerson()=default;
   SearchPerson(DataBase* database): database(database) {}
   ErrorStatus makePersonSearch(std::string username);
private:
   DataBase* database = nullptr;
}

class MakeRequestToPost{
public:
   MakeRequestToPost()=default;
   MakeRequestToPost(DataBase* database): database(database) {}
   ErrorStatus makeReqToPost(RequestToPostData request_info);
private:
   DataBase* database = nullptr;
}

class DeletePost{
public:
   DeletePost()=default;
   DeletePost(DataBase* database): database(database) {}
   ErrorStatus delPostData(int post_id);
private:
   DataBase* database = nullptr;
}

class AnswerTheRequest{
public:
   AnswerTheRequest()=default;
   AnswerTheRequest(DataBase* database): database(database) {}
   ErrorStatus getAnswer(bool answer, RequestToPostData request_info );
private:
   DataBase* database = nullptr;
}

class ShowNotifications{
public:
   ShowNotifications()=default;
   ShowNotifications(DataBase* database): database(database) {}
   ErrorStatus showAllNotifications(int user_id);
private:
   DataBase* database = nullptr;
}

class CreatePost{
public:
   CreatePost()=default;
   CreatePost(DataBase* database): database(database) {}
   ErrorStatus addPostToDB(PostData post);
private:
   DataBase* database = nullptr;
}