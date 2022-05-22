#include "request_response.hpp"


JSON::JSON(const std::string& str): IJSON(str) {
    json::stream_parser p;
    json::error_code ec;

    p.write(str.data(), str.size(), ec);

    if(ec) {
        std::cerr << ec.message();
    }
    p.finish(ec);
    if( ec )
        std::cerr << ec.message();

    value_ =  p.release();
}

template<class T>
T JSON::get(const std::string &key, T defaultValue) {
    json::object obj;
    if(value_.is_null()) {
        obj = value_.emplace_object();
    } else {
        obj = value_.as_object();
    }
    return json::serialize(obj[key]);
}

template<class T>
void JSON::put(const std::string &key, T value) {
    json::object* obj;
    if(value_.is_null()) {
        obj = &value_.emplace_object();
    } else {
        obj = &value_.as_object();
    }
    (*obj)[key] = value;
}
