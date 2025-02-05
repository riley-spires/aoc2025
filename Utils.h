#ifndef UTILS_H 
#define UTILS_H

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <fstream>
#include <regex>

namespace Utils
{
    std::vector<std::string> readInput(std::string filePath) {
        std::ifstream file(filePath);
        std::vector<std::string> lines;

        while (true) {
            std::string line;
            std::getline(file, line);

            if (!file.eof()) lines.push_back(line);
            else break;
        }

        file.close();

        return lines;
    }

    std::string* matches(std::string haystack, std::string needle, int &size) {
        std::smatch matches;

        if (!std::regex_search(haystack, matches, std::regex(needle))) return nullptr;
        
        std::string* ret = new std::string[matches.size()];
        
        for (int i = 0; i < matches.size(); ++i) ret[i] = matches[i];

        size = matches.size();

        return ret;
    }

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
