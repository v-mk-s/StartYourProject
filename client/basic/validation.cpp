#include "validation.hpp"

// ------------------------------------------------------------------
bool isValidEmail(std::string &email)
{
    if ((email.length() < EMAIL_MIN) || (email.length() > EMAIL_MAX))
    {
        return false;
    }

    auto at = std::find(email.begin(), email.end(), '@');
    auto dot = std::find(at, email.end(), '.');

    static const std::regex r(R"([^a-zA-Z0-9_-.])");

    return (at != email.end()) && (dot != email.end()) && (std::regex_search(email.data(), r));
}

bool isValidUsername(std::string &username)
{
    if ((username.length() < USERNAME_MIN) || (username.length() > USERNAME_MAX))
    {
        return false;
    }

    static const std::regex r(R"([^a-zA-Z0-9_-.])");

    return std::regex_search(username.data(), r);
}

bool isValidPassword(std::string &password)
{
    if ((password.length() < PASSWORD_MIN) || (password.length() > PASSWORD_MAX))
    {
        return false;
    }

    static const std::regex r(R"([^a-zA-Z0-9@#$%^&*()_-=+',./[]{}:;\"<>/])");

    return std::regex_search(password.data(), r);
}
// ------------------------------------------------------------------
bool isValidAgeToFrom(std::int32_t age_to, std::int32_t age_from)
{
    if ((age_to < age_from) ||
        (age_from < AGE_MIN) || (age_from > AGE_MAX) ||
        (age_to < AGE_MIN) || (age_to > AGE_MAX))
    {
        return false;
    }

    return true;
}

bool isValidPostTags(std::vector<std::string> &post_tags)
{    
    static const std::regex r(R"([^a-zA-Z0-9])");

    for (auto tag : post_tags)
    {
        if ((tag.length() == 0) || (tag.length() > TAG_MAX))
        {
            return false;
        }

        if (!std::regex_search(tag.data(), r))
            return false;
    }

    return true;
}

// ------------------------------------------------------------------
bool isValidPhoto(std::vector<std::int32_t> &photo)
{
    return true;
}

bool isValidName(std::string &name)
{
    if ((name.length() < NAME_MIN) || (name.length() > NAME_MAX))
    {
        return false;
    }

    static const std::regex r(R"([^a-zA-Z])");

    return std::regex_search(name.data(), r);
}

bool isValidSurname(std::string &surname)
{
    if ((surname.length() < SURNAME_MIN) || (surname.length() > SURNAME_MAX))
    {
        return false;
    }

    static const std::regex r(R"([^a-zA-Z])");

    return std::regex_search(surname.data(), r);
}

bool isValidUserDescription(std::string &description)
{
    std::string stop_symbols_description = "[]{}";

    // static const std::regex r(R"([^a-zA-Z])");

    for (auto c : description)
    {
        if (stop_symbols_description.find(c) != std::string::npos)
        {
            return false;
        }
    }

    return true;
}

///////////////////////

bool isValidProjectName(std::string project) {
    if (project.size() > MAX_PROJECT_NAME || project.size() == 0) {
        return false;
    }

    return true;
}

bool isValidTeamName(std::string team) {
    if (team.size() > MAX_TEAM_NAME || team.size() == 0) {
        return false;
    }

    return true;
}

bool isValidNoSymbol(std::string tag) {
    for (auto c : tag) {
        if (std::find(stop_symbols_all.begin(), stop_symbols_all.end(), c) != stop_symbols_all.end()) {
            return false;
        }
    }

    return true;
}

bool isValidPostTags(std::vector<std::string> post_tags) {
    std::for_each(post_tags.begin(), post_tags.end(), [](std::string tag) {
        return !(tag.size() > MAX_TAG_NAME || !isValidNoSymbol(tag));
    });

    return true;
}

bool isValidTeammates(std::vector<std::string> teammates) {
    std::for_each(teammates.begin(), teammates.end(), [](std::string mate) {
        return !(mate.size() > MAX_TAG_NAME || mate.size() == 0);
    });

    return true;
}


bool isValidProjectDescription(std::string project) {
    if (project.size() > MAX_PROJECT_SIZE) {
        return false;
    }

    return true;
}

// left for Vlad ;)
bool isValidDiversity(int);

bool isValidRequestDescription(std::string request) {
    if (request.size() > MAX_REQUEST_SIZE) {
        return false;
    }

    return true;
}