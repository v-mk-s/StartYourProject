#include "validation.hpp"

static const std::string stop_symbols = "!@#$%^&*(){}[]?:;№/|,.";
static const std::string stop_symbols_email = "!#$%^&*(){}[]?:;№/|,";
// ------------------------------------------------------------------
bool isValidEmail(const std::string &email)
{
    if ((email.length() < EMAIL_MIN) || (email.length() > EMAIL_MAX))
    {
        return false;
    }

    auto at = std::find(email.begin(), email.end(), '@');
    auto dot = std::find(at, email.end(), '.');

    if (at == email.end() && dot == email.end()) {
        return false;
    }

    for (auto c : email) {
        if (std::find(stop_symbols_email.begin(), stop_symbols_email.end(), c) != stop_symbols_email.end()) {
            return false;
        }
    }

    return true;
}

bool isValidUserDescription(const std::string &description)
{
    std::string stop_symbols_staples = "[]{}";

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

    for (auto c : surname) {
        if (std::find(stop_symbols.begin(), stop_symbols.end(), c) != stop_symbols.end()) {
            return false;
        }
    }

    return true;
}

bool isValidUsername(const std::string &username)
{
    if ((username.length() < USERNAME_MIN) || (username.length() > USERNAME_MAX))
    {
        return false;
    }

    for (auto c : username) {
        if (std::find(stop_symbols.begin(), stop_symbols.end(), c) != stop_symbols.end()) {
            return false;
        }
    }

    return true;
}

bool isValidPassword(const std::string &password)
{
    if ((password.length() < PASSWORD_MIN) || (password.length() > PASSWORD_MAX))
    {
        return false;
    }

    for (auto c : password) {
        if (std::find(stop_symbols.begin(), stop_symbols.end(), c) != stop_symbols.end()) {
            return false;
        }
    }

    return true;
}

bool isValidName(const std::string &name)
{
    if ((name.length() < NAME_MIN) || (name.length() > NAME_MAX))
    {
        return false;
    }

    for (auto c : name) {
        if (std::find(stop_symbols.begin(), stop_symbols.end(), c) != stop_symbols.end()) {
            return false;
        }
    }

    return true;
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

    for (auto c : team) {
        if (std::find(stop_symbols.begin(), stop_symbols.end(), c) != stop_symbols.end()) {
            return false;
        }
    }

    return true;
}

bool isValidTeammates(const std::vector<std::string>& teammates)
{
    for (auto mate : teammates) {
        if (mate.size() > MAX_TAG_NAME || mate.size() == 0) {
            return false;
        }

        for (auto c : mate) {
            if (std::find(stop_symbols.begin(), stop_symbols.end(), c) != stop_symbols.end()) {
                return false;
            }
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
