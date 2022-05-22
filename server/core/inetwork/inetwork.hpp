#pragma once

#include "server_utils.hpp"


class RequestInterface {
 public:
    // virtual size_t get_content_size() const = 0;
    virtual std::string get_body() = 0;
};

class ResponseInterface{
 public:
    virtual void set_headers(std::string content_type, int ver) = 0;
    virtual void set_body(std::string body, bool keep_alive) = 0;
};


class IJSON {
 public:
    IJSON(std::string &str);

    template<class T>
    T get(const std::string &str, T);

    template<class T>
    void put(const std::string &str, T);
};
