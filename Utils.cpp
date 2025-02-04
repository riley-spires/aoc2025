#include "Utils.h"

#include <algorithm>
#include <vector>
#include <regex>
#include <fstream>
#include <memory>

namespace Utils {

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

    std::vector<std::string> splitString(std::string input, char delimiter) {
        std::vector<std::string> ret;
        std::string builder = "";

        for (char c : input) {
            if (c == delimiter) {
                ret.push_back(builder);
                builder = "";
                continue;
            }

            builder += c;
        }

        if (input.at(input.length()-1) != delimiter)
            ret.push_back(builder);

        return ret;
    }
}
