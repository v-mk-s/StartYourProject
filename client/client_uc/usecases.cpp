#pragma once

#include "usecases.hpp"
#include "validation.hpp"
#include <sstream>

// ErrorStatus LoginUC::onLoginButton() {
//     // get corresponding info from bars
//     std::string username = getEditLabelData();
//     std::string password = getEditLabelData();

//     if (    !isValidUsername(username) ||
//             !isValidPassword(password))
//     {
//         // mb show error window
//         return ErrorStatus::error;
//     }

//     login_data_.username = username;
//     login_data_.password = password;

//     return ErrorStatus::noError;
// }

// Alex's part

ErrorStatus LoginUC::isValidLoginData(LoginData login) const
{
    if (!isValidUsername(login.username))
    {
        return ErrorStatus::username_not_valid;
    }

    if (!isValidPassword(login.password))
    {
        return ErrorStatus::password_not_valid;
    }

    return ErrorStatus::no_error;
}

ErrorStatus LoginUC::onLoginButtonPress(LoginData login)
{
    ErrorStatus check_input_struct = isValidLoginData(login);
    if (check_input_struct != ErrorStatus::no_error)
    {
        return check_input_struct;
    }

// QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

ErrorStatus RegisterUC::isValidRegisterData(RegisterData reg) const
{
    if (!isValidUsername(reg.username))
    {
        return ErrorStatus::username_not_valid;
    }

    if (!isValidPassword(reg.password))
    {
        return ErrorStatus::password_not_valid;
    }

    if (!isValidEmail(reg.email))
    {
        return ErrorStatus::email_not_valid;
    }

    return ErrorStatus::no_error;
}

ErrorStatus RegisterUC::onRegisterButton(RegisterData reg)
{
    ErrorStatus check_input_struct = isValidRegisterData(reg);
    if (check_input_struct != ErrorStatus::no_error)
    {
        return check_input_struct;
    }

    // get json_data from struct reg

    return ErrorStatus::no_error;
}

// Vlad's part
// --------------------- MainUC --------------------------------------------------
ErrorStatus MainUC::isValidSearchData(SearchData search_data) const
{
    if (!isValidAgeToFrom(search_data.age_from, search_data.age_from))
    {
        return ErrorStatus::age_not_valid;
    }

    if (!isValidPostTags(search_data.post_tags))
    {
        return ErrorStatus::post_tags_not_valid;
    }

    return ErrorStatus::no_error;
}

ErrorStatus MainUC::onSearchButton(SearchData search_data)
{
    ErrorStatus check_input_struct = isValidSearchData(search_data);
    if (check_input_struct != ErrorStatus::no_error)
    {
        return ErrorStatus::error;
    }

// QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

ErrorStatus MainUC::onProjectDescriptionButton(ProjectDescriptionData project_description_data)
{
    ErrorStatus check_input_struct = ErrorStatus::no_error;
    if (check_input_struct != ErrorStatus::no_error)
    {
        return ErrorStatus::error;
    }

// QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

ErrorStatus MainUC::onFindMyDiversityTeamsButton(SearchData search_data)
{
    ErrorStatus check_input_struct = isValidSearchData(search_data);
    if (check_input_struct != ErrorStatus::no_error)
    {
        return ErrorStatus::error;
    }

// QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

// --------------------- PublishPostUC --------------------------------------------------
ErrorStatus PublishPostUC::isValidPhotoData(PhotoData photo_data) const
{
    if (!isValidPhoto(photo_data.photo))
    {
        return ErrorStatus::photo_not_valid;
    }

    return ErrorStatus::no_error;
}

ErrorStatus PublishPostUC::isValidUserEditData(UserEditData user_edit_data) const
{
    if (!isValidUsername(user_edit_data.username))
    {
        return ErrorStatus::username_not_valid;
    }

    if (!isValidEmail(user_edit_data.email))
    {
        return ErrorStatus::email_not_valid;
    }

    if (!isValidName(user_edit_data.name))
    {
        return ErrorStatus::name_not_valid;
    }

    if (!isValidSurname(user_edit_data.surname))
    {
        return ErrorStatus::surname_not_valid;
    }

    if (!isValidUserDescription(user_edit_data.user_description))
    {
        return ErrorStatus::user_description_not_valid;
    }

    if (!isValidPassword(user_edit_data.password))
    {
        return ErrorStatus::password_not_valid;
    }

    if (isValidPhotoData(user_edit_data.photo_data) != ErrorStatus::no_error)
    {
        return ErrorStatus::photo_data_not_valid;
    }

    return ErrorStatus::no_error;
}

ErrorStatus PublishPostUC::onPhotoUploadButton(PhotoData photo_data)
{
    ErrorStatus check_input_struct = isValidPhotoData(photo_data);
    if (check_input_struct != ErrorStatus::no_error)
    {
        return ErrorStatus::error;
    }

// QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

ErrorStatus PublishPostUC::onSaveProfileButton(UserEditData user_edit_data)
{
    ErrorStatus check_input_struct = isValidUserEditData(user_edit_data);
    if (check_input_struct != ErrorStatus::no_error)
    {
        return ErrorStatus::error;
    }

// QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

// --------------------- UserUC --------------------------------------------------
ErrorStatus UserUC::onEditProjectButton(ProjectDescriptionData project_description_data)
{
        // QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

ErrorStatus UserUC::onDelButton(ProjectDescriptionData project_description_data)
{
        // QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

// --------------------- NotificationUC --------------------------------------------------
ErrorStatus NotificationUC::onProjectNameProjectButton(ProjectDescriptionData project_description_data)
{
        // QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

ErrorStatus NotificationUC::onTeamNameProjectButton(ProjectDescriptionData project_description_data)
{
        // QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

ErrorStatus NotificationUC::onProjectProjectDescriptionButton(ProjectDescriptionData project_description_data)
{
        // QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}


ErrorStatus NotificationUC::onProjectNameUserButton(UserDescriptionData user_description_data)
{
        // QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

ErrorStatus NotificationUC::onTeamNameUserButton(UserDescriptionData user_description_data)
{
        // QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

ErrorStatus NotificationUC::onProjectDescriptionUserButton(UserDescriptionData user_description_data)
{
        // QT do it: get json_data from <input> struct and make http

    return ErrorStatus::no_error;
}

// --------------------- TeamPhotosUC --------------------------------------------------
ErrorStatus TeamPhotosUC::onPrevPageButton()
{
    return ErrorStatus::no_error;
}

ErrorStatus TeamPhotosUC::onNextPageButton()
{
    return ErrorStatus::no_error;
}

// --------------------- HelpUC --------------------------------------------------
ErrorStatus HelpUC::onPrevPageButton()
{
    return ErrorStatus::no_error;
}

ErrorStatus HelpUC::onNextPageButton()
{
    return ErrorStatus::no_error;
}
