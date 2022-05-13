#include "handlers.hpp"


template <typename JSON>
void LoginHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    LoginData data;

    data.username = json.template get<std::string>("username", "");
    data.password = json.template get<std::string>("password", "");

    usecase->checkUser(data);
}

template <typename JSON>
void RegisterHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    RegisterData data;

    data.username = json.template get<std::string>("username", "");
    data.password = json.template get<std::string>("password", "");
    data.email = json.template get<std::string>("email", "");

    usecase->addUser(data);
}

template <typename JSON>
void EditProfileHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    UserData data;

    data.username = json.template get<std::string>("username", "");
    data.password = json.template get<std::string>("password", "");
    data.email = json.template get<std::string>("email", "");
    data.name = json.template get<std::string>("name", "");
    data.sur_name = json.template get<std::string>("sur_name", "");
    data.user_discription = json.template get<std::string>("user_discription", "");

    usecase->editUserData(data);
}

template <typename JSON>
void DelUserProfileHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    std::string data;

    data = json.template get<std::string>("username", "");

    usecase->delUserData(data);
}

template <typename JSON>
void GetUserProfileHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    std::string data;

    data = json.template get<std::string>("username", "");

    usecase->getUserData(data);
}
