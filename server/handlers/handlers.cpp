#include "handlers.hpp"


void LoginHandler::handle(RequestInterface* request, ResponseInterface* response) {
    json::stream_parser p;
    json::error_code ec;

    std::string login_data = R"({
    "Login": "User1234",
    "Password": "1234qwerty"
})";

    p.write(login_data.data(), login_data.size(), ec);
    if(ec)
        std::cout << ec.message();
    p.finish(ec);
    if( ec )
        std::cout << ec.message();

    std::string res_text = "Login succes\nLogin data:\n";
    res_text += serialize(p.release());

    response->set_headers("text/plain", 11);
    response->set_body(res_text ,false);
}
