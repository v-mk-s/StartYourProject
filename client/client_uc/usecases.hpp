#pragma once

#include "clientui.hpp"
#include "general.hpp"
#include "client_utils.hpp"

class LoginUC : public ILoginUseCase {
public:
    ErrorStatus onLoginButton(LoginData login) override;

};

class RegisterUC : public IRegisterUseCase {
public:
    ErrorStatus onRegisterButton(RegisterData reg) override;

};

class ProjectUC : public IProject {
public:
    ErrorStatus onRequestToProjectButton(ProjectData request) override;
    
};

class PublishPostUC : public IPublishPost {
    ErrorStatus onGetDataButton(PublishPostData save) override;

};
