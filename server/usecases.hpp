#pragma once

#include "utils.hpp"


class ServerUseCases {
 public:
    ServerUseCases();
};


class LoginUC : public ServerUseCases {
 public:
    Response checkUserInDB(LoginData user);
};
