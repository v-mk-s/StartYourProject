#pragma once

#include "server_utils.hpp"


class RequestInterface {
 public:
    virtual std::string get_body() = 0;
    virtual bool is_keep_alive() = 0;
};

class ResponseInterface{
 public:
    virtual void set_status(ResponseStatus status, bool keep_alive = false, int ver = HTTP_VER_1_1) = 0;
    virtual void set_content_type(std::string content_type) = 0;
    virtual void set_body(const std::string& body) = 0;
};


class IJSON {
 public:
    IJSON(const std::string &) {};

    template<class T>
    T get(const std::string &key, T);

    template<class T>
    void put(const std::string &key, T);

    template <typename T>
    void put(const std::string &key, const std::vector<T> &values);

    virtual std::string serialize() = 0;
};
