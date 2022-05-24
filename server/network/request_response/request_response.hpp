#pragma once

#include "inetwork.hpp"

#include <boost/beast/http.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/json.hpp>

namespace beast = boost::beast;
namespace http = beast::http;
namespace json = boost::json;

#define SERVER_NAME "StartYourProject"



template <typename BodyType = http::string_body>
class Request: public RequestInterface {
 public:
    Request() = default;
    Request(http::request<BodyType> req): req_(req) {}

    std::string get_body() override { return req_.body(); }
    bool is_keep_alive() override {return req_.keep_alive() ;}

    http::request<BodyType>& get_reference() { return req_; }

 private:
    http::request<BodyType> req_;
};


template <typename BodyType = http::string_body>
class Response: public ResponseInterface {
 public:
    Response() = default;

    void set_headers(ResponseStatus status, std::string content_type, int ver, bool keep_alive) override;

    void set_body(std::string& body) override;

    http::response<BodyType>& get_reference() { return res_; }

 private:
    http::response<BodyType> res_;
};


class JSON: public IJSON {
 public:
    JSON(const std::string &str);

    template<class T>
    T get(const std::string &key, T defaultValue);

    template<class T>
    void put(const std::string &key, T value);

 private:
    json::value value_;
};

#include "request_response.impl"
