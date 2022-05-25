#include "server.hpp"


int main(int argc, char* argv[]) {
    auto const address = argc > 1 ? net::ip::make_address(argv[1]) : default_address;
    auto const port = argc > 2 ? static_cast<unsigned short>(std::atoi(argv[2])) : default_port;
    auto const doc_root = argc > 3 ? std::make_shared<std::string>(argv[3]) : default_doc_root;
    auto const threads = argc > 4 ? std::max<int>(1, std::atoi(argv[4])) : default_threads;

    // Server server(address, port, doc_root, threads);
    // server.start();

    return EXIT_SUCCESS;
}
