#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/strand.hpp>
#include <boost/optional.hpp>


namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

#define ADDRESS "0.0.0.0"
#define PORT 8080
#define DOC_ROOT "."
#define THREADS 4

#define SERVER_NAME "StartYourProject"
