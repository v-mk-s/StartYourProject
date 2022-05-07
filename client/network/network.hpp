#pragma once
#include "clientui.hpp"
#include "usecases.hpp"

#include <functional>
#include <sstream>
// #include <any>


class IResponce {
public:
    // void getAns();
};
 
class INet {
public:
    virtual ErrorStatus onMakeRequest(const std::ostringstream& json_data) = 0;
    virtual ErrorStatus onGetResponse(IResponce* responce) = 0;
};

class LoginNet : public INet {
public:
    LoginNet() = default;

    ErrorStatus onMakeRequest(const std::ostringstream& json_data) override;
    ErrorStatus onGetResponse(IResponce* responce) override;

};

class RegisterNet : public INet {
public:
    RegisterNet() = default;

    ErrorStatus onMakeRequest(const std::ostringstream& json_data) override;
    ErrorStatus onGetResponse(IResponce* responce) override;

};

