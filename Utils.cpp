#include "Utils.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <fstream>
#include <memory>
#include <functional>

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

}

/*int main() {*/
/*    std::string sentence = "hehe hoo ha";*/
/**/
/*    auto words = Utils::splitString<std::string>(sentence);*/
/**/
/**/
/*    for (auto word : words) std::cout << word << std::endl;*/
/*}*/
