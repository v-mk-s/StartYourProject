#include "listener.hpp"


int main()
{
    auto const address = net::ip::make_address(ADDRESS);
    auto const port = static_cast<unsigned short>(PORT);
    auto const doc_root = std::make_shared<std::string>(DOC_ROOT);
    auto const threads = std::max<int>(1, THREADS);

    net::io_context ioc{threads};

    std::make_shared<Listener>(ioc, tcp::endpoint{address, port}, doc_root)->run();

    net::signal_set signals(ioc, SIGINT, SIGTERM);
    signals.async_wait([&] (beast::error_code const&, int) { ioc.stop(); });

    std::vector<std::thread> v;
    v.reserve(threads - 1);
    for(auto i = threads - 1; i > 0; --i) {
        v.emplace_back([&ioc] { ioc.run(); });
    }

    ioc.run();

    for(auto& t : v) {
        t.join();
    }

    return EXIT_SUCCESS;
}
