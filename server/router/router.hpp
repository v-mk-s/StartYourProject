#pragma once

#include <string>
#include <boost/beast/http.hpp>

namespace http = boost::beast::http;


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


template <typename BodyType = http::string_body>
class Request: public RequestInterface {
 public:
    Request() = default;
    Request(http::request<BodyType> req): req_(req) {}

    // size_t get_content_size() const { return req_.payload_size(); }
    std::string get_body() { return req_.body(); }

    http::request<BodyType>& get_reference() { return req_; }

 private:
    http::request<BodyType> req_;
};


template <typename BodyType = http::string_body>
class Response: public ResponseInterface {
 public:
    Response() = default;

    void set_headers(std::string content_type, int ver);

    void set_body(std::string body, bool keep_alive);

    http::response<BodyType>& get_reference() { return res_; }

 private:
    http::response<BodyType> res_;
};
