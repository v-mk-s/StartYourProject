#pragma once

#include "listener.hpp"
#include "handlers.hpp"
#include "database.hpp"
#include "utils.hpp"

#include <boost/beast/core.hpp>
#include <boost/asio/signal_set.hpp>

#include <string>
#include <map>
#include <vector>
#include <thread>

namespace beast = boost::beast;
namespace net = boost::asio;

using tcp = boost::asio::ip::tcp;


auto static const default_address = net::ip::make_address("0.0.0.0");
static constexpr unsigned short default_port = 8080;
static std::shared_ptr<std::string> default_doc_root = std::make_shared<std::string>("/tmp");
static constexpr int default_threads = 1;



class Server {
 public:
    Server(boost::asio::ip::address address, unsigned short port,
           std::shared_ptr<std::string> doc_root, int n_threads);

    void start();

 private:
    class ServerImpl {
     public:
        ServerImpl(boost::asio::ip::address address, unsigned short port,
                    std::shared_ptr<std::string> doc_root, int threads);

        ServerImpl(const ServerImpl& other) = delete;
        ServerImpl& operator=(const ServerImpl& other) = delete;

        void start();

        ~ServerImpl();

     private:
        boost::asio::ip::address address_;
        unsigned short port_;
        std::shared_ptr<std::string> doc_root_;
        int n_threads_;

        net::io_context ioc_;
        net::signal_set signals_;
        std::vector<std::thread> threads_;

        MySQLConnection sql_conn_;
        MainDataBase database_;

        std::map<std::string, IHandler*> handlers_;
    };
    
    std::unique_ptr<ServerImpl> impl_;
};
