#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <memory>

namespace Utils
{
    std::vector<std::string> readInput(std::string);

    std::string* matches(std::string, std::string, int&);

    std::vector<std::string> splitString(std::string, char delimiter = ' ');
}

#endif
