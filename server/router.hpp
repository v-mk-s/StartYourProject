#pragma once

#include <list>
#include "utils.hpp"
#include "handlers.hpp"


class Router {
 public:
    Router();

    ErrorStatus addRoute(std::string url, IHandler handler);
    Request onNewRequest(std::string url);
    ErrorStatus getParams(std::string url, Response response);

 private:
    std::list<IHandler> _handlers;
};
