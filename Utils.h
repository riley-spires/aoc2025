#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <memory>

namespace Utils
{
    std::vector<std::string> readInput(std::string);

    std::string* matches(std::string, std::string, int&);
}

#endif
