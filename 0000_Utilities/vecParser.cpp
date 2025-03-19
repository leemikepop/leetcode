#include "vecParser.hpp"

#include <iostream>
#include <sstream>

std::vector<int> parseLine(const std::string &line) {
    std::vector<int> ret;
    std::stringstream ss(line);
    char c;

    while (ss >> c) {
        if (c == ',' || c == '[' || c == ' '){
            int value;
            if (ss >> value) {
                ret.push_back(value);
            }
        }
    }
    return ret;
}

std::vector<std::pair<std::vector<int>, std::vector<int>>>
parseInput(const std::string &input) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> result;
    std::stringstream ss(input);
    std::string line1, line2;

    while (std::getline(ss, line1)) {
        std::getline(ss, line2);
        if (!line1.empty() && !line2.empty()) {
            result.push_back(
                std::make_pair(parseLine(line1), parseLine(line2)));
        }
    }

    return result;
}