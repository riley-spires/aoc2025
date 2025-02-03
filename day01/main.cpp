#include "../Utils.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <format>

void part1(std::vector<std::string>);
void part2(std::vector<std::string>);

#if 0
    const std::string INPUT_FILE = "input.txt";
#else
    const std::string INPUT_FILE = "sample.txt";
#endif

const std::string pattern = R"((\d+)\s*(\d+))";

int main() {
    std::vector<std::string> lines = Utils::readInput(INPUT_FILE);

    part1(lines);
    part2(lines);

    return 0;
}

void part1(std::vector<std::string> lines) {
    int size = lines.size();
    int left[size], right[size];

    for (int i = 0; i < size; ++i) {
        std::string line = lines[i];

        int size = 0;
        auto matches = Utils::matches(line, pattern, size);

        if (matches == nullptr) {
            throw std::invalid_argument("Invalid line");
        }

        left[i] = std::stoi(matches[1]);
        right[i] = std::stoi(matches[2]);

        delete[] matches;
    }

    std::sort(left, left + size);
    std::sort(right, right + size);

    int total = 0;

    for (int i = 0; i < size; ++i) {
        total += std::abs(std::abs(left[i]) - std::abs(right[i]));
    }

    std::cout << "Part 1: " << total << std::endl;
}

void part2(std::vector<std::string> lines) {
    int size = lines.size();
    int left[size];
    std::map<int, int> occurances;

    for (int i = 0; i < size; ++i) {
        std::string line = lines[i];

        int size;

        auto matches = Utils::matches(line, pattern, size);

        if (matches == nullptr) throw std::invalid_argument("Invalid line");

        left[i] = std::stoi(matches[1]);

        int right = std::stoi(matches[2]);

        if (occurances[right]) {
            occurances[right] = occurances[right] + 1;
        } else {
            occurances[right] = 1;
        }


        delete[] matches;
    }


    int sum = 0;

    for (const auto num : left) {
        sum += num * occurances[num];
    }

    std::cout << "Part 2: " << sum << std::endl;
}
