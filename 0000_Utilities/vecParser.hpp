#ifndef VECPARSER_HPP
#define VECPARSER_HPP

#include <vector>
#include <string>
#include <utility>		//pair

std::vector<int> parseLine(const std::string& line);
std::vector<std::pair<std::vector<int>, std::vector<int>>> parseInput(const std::string& input);

#endif // VECPARSER_HPP