#ifndef GENERAL_H
#define GENERAL_H

#include <vector>
#include <string>
#include "utils.hpp"
#include <memory>

class general
{
public:
    general();
};

std::vector<std::string> getVectorFromString(const std::string& string);

struct Context {
    UserData _user_data;
    ProjectData _project_data;

    UserData& getUserData() { return _user_data; }
    ProjectData& getProjectData() { return _project_data; }

};

#endif // GENERAL_H
