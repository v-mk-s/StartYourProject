#include "validation.hpp"

// ------------------------------------------------------------------
bool isValidEmail(const std::string &email)
{
    if ((email.length() < EMAIL_MIN) || (email.length() > EMAIL_MAX))
    {
        return false;
    }

    auto at = std::find(email.begin(), email.end(), '@');
    auto dot = std::find(at, email.end(), '.');

    static const std::regex r(R"([^a-zA-Z0-9])");

    return (at != email.end()) && (dot != email.end()) && (std::regex_search(email.data(), r));
}

bool isValidUserDescription(const std::string &description)
{
    std::string stop_symbols_staples = "[]{}";

    // static const std::regex r(R"([^a-zA-Z])");

    for (auto c : description)
    {
        if (stop_symbols_staples.find(c) != std::string::npos)
        {
            return false;
        }
    }

    return true;
}

bool isValidSurname(const std::string &surname)
{
    if ((surname.length() < SURNAME_MIN) || (surname.length() > SURNAME_MAX))
    {
        return false;
    }

    static const std::regex r(R"([^a-zA-Z])");

    return !std::regex_search(surname.data(), r);
}

bool isValidUsername(const std::string &username)
{
    if ((username.length() < USERNAME_MIN) || (username.length() > USERNAME_MAX))
    {
        return false;
    }

    static const std::regex r(R"([^a-zA-Z0-9])");

    return !std::regex_search(username.data(), r);
}

bool isValidPassword(const std::string &password)
{
    if ((password.length() < PASSWORD_MIN) || (password.length() > PASSWORD_MAX))
    {
        return false;
    }

    static const std::regex r(R"([^a-zA-Z0-9])");

    return !std::regex_search(password.data(), r);
}

bool isValidName(const std::string &name)
{
    if ((name.length() < NAME_MIN) || (name.length() > NAME_MAX))
    {
        return false;
    }

    static const std::regex r(R"([^a-zA-Z])");

    return !std::regex_search(name.data(), r);
}

bool isValidProjectName(const std::string& project) {
    if (project.size() > MAX_PROJECT_NAME || project.size() == 0) {
        return false;
    }

    return true;
}

bool isValidTeamName(const std::string& team) {
    if (team.size() > MAX_TEAM_NAME || team.size() == 0) {
        return false;
    }

    static const std::regex r(R"([^a-zA-Z])");

    return !std::regex_search(team.data(), r);
}

bool isValidTeammates(const std::vector<std::string>& teammates)
{
    static const std::regex r(R"([^a-zA-Z0-9])");

    for (auto mate : teammates) {
        if (mate.size() > MAX_TAG_NAME || mate.size() == 0) {
            return false;
        }

        if (std::regex_search(mate.data(), r)) {
            return false;
        }
    }

    return true;
}

bool isValidPostTags(const std::vector<std::string> &post_tags)
{    
    for (auto tag : post_tags)
    {
        if ((tag.length() == 0) || (tag.length() > TAG_MAX) || (tag[0] != '#')) {
            return false;
        }
    }

    return true;
}

bool isValidProjectDescription(const std::string& project) {
    if (project.size() > MAX_PROJECT_SIZE) {
        return false;
    }

    return true;
}






// ------------------------------------------------------------------


// bool isValidAgeToFrom(const std::int32_t &age_to, const std::int32_t &age_from)
// {
//     if ((age_to < age_from) ||
//         (age_from < AGE_MIN) || (age_from > AGE_MAX) ||
//         (age_to < AGE_MIN) || (age_to > AGE_MAX))
//     {
//         return false;
//     }

//     return true;
// }


// ------------------------------------------------------------------
// bool isValidPhoto(const std::vector<std::int32_t> &photo)
// {
//     return true;
// }






///////////////////////


// bool isValidNoSymbol(const std::string& tag) {
//     // for (auto c : tag) {
//     //     if (std::find(stop_symbols_all.begin(), stop_symbols_all.end(), c) != stop_symbols_all.end()) {
//     //         return false;
//     //     }
//     // }

//     // return true;

//     static const std::regex r(R"([^a-zA-Z])");

//     return std::regex_search(tag.data(), r);
// }

// redefinition
// bool isValidPostTags(const std::vector<std::string>& post_tags) {
//     std::for_each(post_tags.begin(), post_tags.end(), [](std::string tag) {
//         return !(tag.size() > MAX_TAG_NAME || !isValidNoSymbol(tag));
//     });

//     return true;
// }




// left for Vlad ;)
// bool isValidDiversity(int diversity) {
//     if (diversity > 100) {
//         return false;
//     }

//     return true;
// }

// bool isValidRequestDescription(const std::string& request) {
//     if (request.size() > MAX_REQUEST_SIZE) {
//         return false;
//     }

//     return true;
// }