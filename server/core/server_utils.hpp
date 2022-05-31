#pragma once

#include "utils.hpp"
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>


enum class ResponseStatus {
    ok = 200,
    bad_req = 400,
    unauthorized = 401,
    forbidden = 403,
    not_found = 404,
    conflict = 409,
    not_implemented = 501,
    server_error = 503
};

enum class DBStatus {
    ok,
    not_found,
    unknown
};


template <typename MessageData, typename Status = ResponseStatus>
struct Message {
    Status status;
    std::string status_text;
    MessageData data;

    Message() = delete;
    Message(Status status, std::string text = ""): status(status), status_text(text) {}
    Message(MessageData data): status(Status::ok), data(data) {}
};
