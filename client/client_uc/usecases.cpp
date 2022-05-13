#pragma once

#include "usecases.hpp"
#include "validation.hpp"
#include <sstream>


ErrorStatus LoginUC::onLoginButton(LoginData login) {
    if (!isValidUsername(login.username)) {
        return ErrorStatus::username_not_valid;
    }

    if (!isValidPassword(login.password)) {
        return ErrorStatus::password_not_valid;
    }

    return ErrorStatus::no_error;
}

ErrorStatus RegisterUC::onRegisterButton(RegisterData reg) {
    if (!isValidUsername(reg.username)) {
        return ErrorStatus::username_not_valid;
    }

    if (!isValidPassword(reg.password)) {
        return ErrorStatus::password_not_valid;
    }

    if (!isValidEmail(reg.email)) {
        return ErrorStatus::email_not_valid;
    }

    return ErrorStatus::no_error;
}

ErrorStatus ProjectUC::onRequestToProjectButton(ProjectData request) {
    if (!isValidRequestDescription(request.request_description)) {
        return ErrorStatus::request_description_not_valid;
    }

    return ErrorStatus::no_error;
}



ErrorStatus PublishPostUC::onGetDataButton(PublishPostData save) {
    if (!isValidProjectName(save.project_name)) {
        return ErrorStatus::project_name_not_valid;
    }

    if (!isValidTeamName(save.team_name)) {
        return ErrorStatus::team_name_not_valid;
    }

    if (!isValidPostTags(save.post_tags)) {
        return ErrorStatus::post_tags_not_valid;
    }

    if (!isValidTeammates(save.teammates)) {
        return ErrorStatus::teammates_not_valid;
    }

    if (!isValidProjectDescription(save.project_description)) {
        return ErrorStatus::project_description_not_valid;
    }

    return ErrorStatus::no_error;
}
