#pragma once

#include "server_utils.hpp"


class RequestInterface {
 public:
    virtual std::string get_body() = 0;
    virtual bool is_keep_alive() = 0;
};

class ResponseInterface{
 public:
    virtual void set_headers(ResponseStatus status, std::string content_type, int ver, bool keep_alive) = 0;
    virtual void set_body(std::string& body) = 0;
};


class IJSON {
 public:
    IJSON(const std::string &) {};

    template<class T>
    T get(const std::string &str, T);

    template<class T>
    void put(const std::string &str, T);
};
