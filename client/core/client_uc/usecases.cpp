#pragma once

#include "usecases.hpp"
#include "validation.hpp"
#include <sstream>


ErrorStatus LoginUC::onLoginButton(const UserData& login) {
    if (!isValidUsername(login.username)) {
        return ErrorStatus::username_not_valid;
    }

    if (!isValidPassword(login.password)) {
        return ErrorStatus::password_not_valid;
    }

    return ErrorStatus::no_error;
}

ErrorStatus RegisterUC::onRegisterButton(const UserData& reg) {
    if (!isValidEmail(reg.email)) {
        return ErrorStatus::email_not_valid;
    }

    if (!isValidUsername(reg.username)) {
        return ErrorStatus::username_not_valid;
    }

    if (!isValidPassword(reg.password)) {
        return ErrorStatus::password_not_valid;
    }

    return ErrorStatus::no_error;
}

ErrorStatus PublishPostUC::onGetDataButton(const ProjectData& save) {
    if (!isValidProjectName(save.project_name)) {
        return ErrorStatus::project_name_not_valid;
    }

    if (!isValidTeamName(save.team_name)) {
        return ErrorStatus::team_name_not_valid;
    }

    if (!isValidTeammates(save.teammates)) {
        return ErrorStatus::teammates_not_valid;
    }

    if (!isValidPostTags(save.post_tags)) {
        return ErrorStatus::post_tags_not_valid;
    }

    if (!isValidProjectDescription) {
        return ErrorStatus::project_description_not_valid;
    }

    return ErrorStatus::no_error;
}

ErrorStatus UserEditUC::onEditUserDataButton(const UserData& user_data) {
    if (!isValidUsername(user_data.username)) {
        return ErrorStatus::username_not_valid;
    }

    if (!isValidEmail(user_data.email)) {
        return ErrorStatus::email_not_valid;
    }

    if (!isValidName(user_data.name)) {
        return ErrorStatus::name_not_valid;
    }

    if (!isValidSurname(user_data.sur_name)) {
        return ErrorStatus::surname_not_valid;
    }

    if (!isValidUserDescription(user_data.user_discription)) {
        return ErrorStatus::user_description_not_valid;
    }

    if (!isValidPassword(user_data.password)) {
        return ErrorStatus::password_not_valid;
    }

    return ErrorStatus::no_error;
}
