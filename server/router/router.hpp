#pragma once


class RequestInterface {
 public:
    virtual std::string get_path() = 0;
    virtual std::string get_pass() = 0;
    virtual std::string get_header() = 0;
    virtual std::string get_files() = 0;
    virtual std::string get_content() = 0;
};

class ResponseInterface{
 public:
    virtual std::string get_header() = 0;
};

