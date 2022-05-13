#include "validation.hpp"

bool isValidEmail(std::string email) {
    if (email.find("@") == -1) {
        return false;
    }

    for (auto c : email) {
        if (stop_symbols_email.find(c) != -1) {
            return false;
        }
    }

    return true;
}

bool isValidUsername(std::string username) {
    for (auto c : username) {
        if (stop_symbols_all.find(c) != -1) {
            return false;
        }
    }
    return true;
}

bool isValidPassword(std::string password) {
    if (password.size() < 8) {
        return false;
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
        if (tag.size() > MAX_TAG_NAME || !isValidNoSymbol(tag)) {
            return false;
        }
    });

    return true;
}

bool isValidTeammates(std::vector<std::string> teammates) {
    std::for_each(teammates.begin(), teammates.end(), [](std::string mate) {
        if (mate.size() > MAX_TAG_NAME || mate.size() == 0) {
            return false;
        }
    });

    return true;
}


bool isValidProjectDescription(std::string project) {
    if (project.size() > MAX_PROJECT_SIZE || project.size() == 0) {
        return false;
    }

    return true;
}

// left for Vlad ;)
bool isValidDiversity(int);

bool isValidRequestDescription(std::string request) {
    if (request.size() > MAX_REQUEST_SIZE || request.size() == 0) {
        return false;
    }

    return true;
}