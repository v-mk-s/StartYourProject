#include "general.h"

general::general()
{

}

std::vector<std::string> getVectorFromString(const std::string& string) {
    std::string temp = "";
    std::vector<std::string> vec;
    for (auto c : string) {
        if (c == ' ') {
            if (temp.size() != 0) {
                vec.push_back(temp);
                temp = "";
            }
        } else {
            temp += c;
        }
    }

    if (temp.size() != 0) {
        vec.push_back(temp);
    }

    return vec;
}


std::string getStringFromVector(const std::vector<std::string>& vector) {
    std::string result;

    for (int i = 0; i < vector.size(); ++i) {
        result += vector[i] + " ";
    }

    return result;
}
