#pragma once

#include "network.hpp"

void RegisterNet::onMakeRequest(std::any data) {
    RegisterData temp = std::any_cast<RegisterData>(data);

    // later
}

void RegisterNet::onGetResponse(QNetworkReply* reply) {
    // later
}

// add same impl of another usecases ...
