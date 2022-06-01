#pragma once

#include "utils.hpp"

#define WRONG_AGE "Wrong age: TENET?"
#define WRONG_NAME "Username is incorrect"
#define WRONG_PASSWORD "Password is incorrect"
#define WRONG_EMAIL "Email is incorrect"
#define LOGIN_DATA_DONT_MATCH "Username and password dont match"
#define SAME_USER "A user with the same name already exists"

//--------------remake all------------------//

class ILoginUseCase {
public:
    virtual ErrorStatus onLoginButton(const UserData& login) = 0;

};

class IRegisterUseCase {
public:
    virtual ErrorStatus onRegisterButton(const UserData& reg) = 0;

};


class IPublishPostUseCase {
public:
    virtual ErrorStatus onGetDataButton(const ProjectData& save) = 0;

};

class IUserEditUseCase
{
public:
    virtual ErrorStatus onEditUserDataButton(const UserData& project_description_data) = 0;

};




class LoginUC : public ILoginUseCase {
public:
    ErrorStatus onLoginButton(const UserData& login) override;

};

class RegisterUC : public IRegisterUseCase {
public:
    ErrorStatus onRegisterButton(const UserData& reg) override;

};

class PublishPostUC : public IPublishPostUseCase {
public:
    ErrorStatus onGetDataButton(const ProjectData& save) override;

};

class UserEditUC : public IUserEditUseCase {
public:
    ErrorStatus onEditUserDataButton(const UserData& project_description_data) override;

};