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
    not_implemented = 501,
    server_error = 503
};


template <typename MessageData>
struct Message {
    ResponseStatus status = ResponseStatus::server_error;
    std::string status_text;
    MessageData data;

    Message() = default;
    Message(ResponseStatus status, std::string text = ""): status(status), status_text(text) {}
    Message(MessageData data): status(ResponseStatus::ok), data(data) {}
};
