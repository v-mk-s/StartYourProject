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
    ok,
    bad_req,
    not_found,
    server_error,
    wrong_data
};


template <typename MessageData>
struct Message {
    ResponseStatus status = ResponseStatus::server_error;
    MessageData data = MessageData();

    Message() = default;
    Message(ResponseStatus status): status(status) {}
    Message(ResponseStatus status, MessageData data): status(status), data(data) {}
};
