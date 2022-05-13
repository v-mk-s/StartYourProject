#pragma once

#include "client_utils.hpp"

// for each usecase own interface class

class ILoginUseCase {
public:
    virtual ErrorStatus onLoginButton(LoginData login) = 0;

};

class IRegisterUseCase {
public:
    virtual ErrorStatus onRegisterButton(RegisterData reg) = 0;

};

class IProject {
public:
    virtual ErrorStatus onRequestToProjectButton(ProjectData request) = 0;

};

class IPublishPost {
public:
    virtual ErrorStatus onGetDataButton(PublishPostData save) = 0;

};
