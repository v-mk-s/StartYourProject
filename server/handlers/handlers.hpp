#pragma once

#include "utils.hpp"
#include "server_usecases.hpp"


class IHandler {
 public:
    IHandler();
};


class LoginHandler: public IHandler {
 public:
    Response Handler(Request requestLogin);

 private:
    LoginUC usecase;
};


class RegisterHandler: public IHandler {
 public:
    Response Handler(Request requestRegister);

 private:
    RegisterUC usecase;
};


class EditProfileHandler: public IHandler {
 public:
    Response Handler(Request requestEditProfile);

 private:
    EditProfileUC usecase;
};
