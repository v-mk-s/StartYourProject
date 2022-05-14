#pragma once

#include <string>

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
