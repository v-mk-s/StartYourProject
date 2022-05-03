#include "router.hpp"


// template <typename BodyType>
// void Response<BodyType>::set_headers(std::string content_type, int ver) {
//     res_ = {http::status::ok, ver};
//     res_.set(http::field::version, ver);
//     res_.set(http::field::server, SERVER_NAME);
//     res_.set(http::field::content_type, content_type);
// }

// template <typename BodyType>
// void Response<BodyType>::set_body(std::string body, bool keep_alive) {
//     res_.content_length(body.size());
//     res_.body() = body;
//     res_.keep_alive(keep_alive);
// }
