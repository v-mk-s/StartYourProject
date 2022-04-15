#pragma once

#include "utils.hpp"
#include "usecases.hpp"


class IHandler {
 public:
    IHandler();
};

class LoginHandler {
 public:
    Response Handler(Request requestLogin);

 private:
    ServerUseCases useCases;
};