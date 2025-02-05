#ifndef UTILS_H 
#define UTILS_H

#include <string>
#include <vector>
#include <memory>
#include <functional>

namespace Utils
{
    std::vector<std::string> readInput(std::string);

    std::string* matches(std::string, std::string, int&);

    template <typename T = std::string>
    std::vector<T> splitString(std::string input,
                               char delimiter = ' ',
                               std::function<T(std::string)> conversionFunction = [](const std::string &str) { return str; } ) {
        std::vector<T> ret;
        std::string builder = "";
        T builderConverted;

        for (char c : input) {
            if (c == delimiter) {
                T builderConverted = conversionFunction(builder);
                ret.push_back(builderConverted);
                builder = "";
                continue;
            }

            builder += c;
        }

        if (input.at(input.length()-1) != delimiter) {
            T builderConverted = conversionFunction(builder);
            ret.push_back(builderConverted);
        }

        return ret;
    }
}

#endif
