#include "handlers.hpp"


void LoginHandler::handle(RequestInterface* request, ResponseInterface* response) {
    response->set_headers("text/plain", 11);
    response->set_body("Login succes", false);
}
