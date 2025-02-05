#include <iostream>
#include "../Utils.h"

#if 1
const std::string INPUT_PATH = "./input.txt";
#else
const std::string INPUT_PATH = "./sample.txt";
#endif

void part1(std::vector<std::string>);
void part2(std::vector<std::string>);

int main() {
    auto lines = Utils::readInput(INPUT_PATH);

    part1(lines);
    part2(lines);
}

void part1(std::vector<std::string> lines) {
    int safeLines = 0;

    for (const std::string line : lines) {
        auto stoi_bound = [](const std::string& str) { return std::stoi(str); };
        auto nums = Utils::splitString<int>(line, ' ', stoi_bound);
        const int SIZE = nums.size();
        

        bool increasing = nums[0] < nums[1];
        bool cont = false;


        for (int i = 0; i < SIZE-1; ++i) {
            if (increasing) {
                if (nums[i] > nums[i+1]) {
                    /*std::cout << "'" << line << "'  is unsafe due to increasing becoming decreasing" << std::endl;*/
                    cont = true;
                    break;
                }
            } else {
                if (nums[i] < nums[i+1]) {
                    /*std::cout << "'" << line << "' is unsafe due to decreasing becoming increasing" << std::endl;*/
                    cont = true;
                    break;
                }
            }

            int difference = std::abs(nums[i] - nums[i+1]);

            if (difference > 3) {
                /*std::cout << "'" << line << "' is unsafe due to high jump" << std::endl;*/
                cont = true;
                break;
            }

            if (difference < 1) {
                /*std::cout << "'" << line << "' is unsafe due to zero jump" << std::endl;*/
                cont = true;
                break;
            }
        }

        if (cont) {
            continue;
        }

        /*std::cout << "'" << line << "' is safe!" << std::endl;*/
        safeLines += 1;
    }


    std::cout << "Part 1: " << safeLines << std::endl;
}


void part2(std::vector<std::string> lines) {
    // TODO
}
