#pragma once

#include "utils.hpp"
#include <string>


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


class IJSON {
 public:
    IJSON(std::string &str);

    template<class T>
    T get(const std::string &str, T);

    template<class T>
    void put(const std::string &str, T);
};
