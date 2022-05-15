#pragma once

#include "router.hpp"
#include "server_utils.hpp"
#include "server_usecases.hpp"


class IHandler {
 public:
    virtual void handle(RequestInterface* request, ResponseInterface* response) = 0;
};


/////////////////////// User Handlers ///////////////////////////////////

template <typename JSON>
class LoginHandler: public IHandler {
 public:
    LoginHandler() = default;
    LoginHandler(ILoginUC* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    ILoginUC* usecase = nullptr;
};


template <typename JSON>
class RegisterHandler: public IHandler {
 public:
    RegisterHandler() = default;
    RegisterHandler(IRegisterUC* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IRegisterUC* usecase = nullptr;
};


template <typename JSON>
class EditProfileHandler: public IHandler {
 public:
    EditProfileHandler() = default;
    EditProfileHandler(IEditProfileUC* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IEditProfileUC* usecase = nullptr;
};


template <typename JSON>
class DelUserProfileHandler: public IHandler {
 public:
    DelUserProfileHandler() = default;
    DelUserProfileHandler(IDelUserProfileUC* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IDelUserProfileUC* usecase = nullptr;
};


template <typename JSON>
class GetUserProfileHandler: public IHandler {
 public:
    GetUserProfileHandler() = default;
    GetUserProfileHandler(IGetUserProfileUC* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IGetUserProfileUC* usecase = nullptr;
};


/////////////////////////// Posts Handlers ////////////////////////////////

template <typename JSON>
class EditPostHandler: public IHandler {
 public:
    EditPostHandler() = default;
    EditPostHandler(IEditPost* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IEditPost* usecase = nullptr;
};


template <typename JSON>
class SearchPostHandler: public IHandler {
 public:
    SearchPostHandler() = default;
    SearchPostHandler(ISearchPost* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    ISearchPost* usecase = nullptr;
};


template <typename JSON>
class SearchPersonHandler: public IHandler {
 public:
    SearchPersonHandler() = default;
    SearchPersonHandler(ISearchPerson* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    ISearchPerson* usecase = nullptr;
};


template <typename JSON>
class MakeRequestToPostHandler: public IHandler {
 public:
    MakeRequestToPostHandler()=default;
    MakeRequestToPostHandler(IMakeRequestToPost* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IMakeRequestToPost* usecase = nullptr;
};


template <typename JSON>
class ShowNotificationsHandler: public IHandler {
 public:
    ShowNotificationsHandler() = default;
    ShowNotificationsHandler(IShowNotifications* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IShowNotifications* usecase = nullptr;
};


template <typename JSON>
class AnswerTheRequestHandler: public IHandler {
 public:
    AnswerTheRequestHandler()=default;
    AnswerTheRequestHandler(IAnswerTheRequest* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IAnswerTheRequest* usecase = nullptr;
};


template <typename JSON>
class DeletePostHandler: public IHandler {
 public:
    DeletePostHandler() = default;
    DeletePostHandler(IDeletePost* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    IDeletePost* usecase = nullptr;
};


template <typename JSON>
class CreatePostHandler: public IHandler {
 public:
    CreatePostHandler() = default;
    CreatePostHandler(ICreatePost* usecase): usecase(usecase) {}

    void handle(RequestInterface* request, ResponseInterface* response);

 private:
    ICreatePost* usecase = nullptr;
};
