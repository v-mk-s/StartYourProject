#pragma once

#include "utils.hpp"

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/strand.hpp>
#include <boost/optional.hpp>

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

#define ADDRESS "0.0.0.0"
#define PORT 8080
#define DOC_ROOT "."
#define THREADS 4


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
