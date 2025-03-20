/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <unordered_map>

using std::vector;
using std::string;

/*overload ostream << to print a vector of vectors*/
template <typename T> struct is_container {
    static constexpr bool value = false;
};
template <typename T, typename Allocator>
struct is_container<vector<T, Allocator>> {
    static constexpr bool value = true;
};
template <typename T>
typename std::enable_if<is_container<T>::value, std::ostream &>::type
inline operator<<(std::ostream &os, const T &container) {
    const auto N = container.size();
    size_t current = 0;
    os << "[";
    for (const auto &item : container) {
    const char *separator = current++ == N - 1 ? "" : ", ";
    os << item << separator;
    }
    os << "]";
    return os;
} 

class Solution {
public:
    std::unordered_map<char, vector<char>> phone_map = {
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}
    };

    void backtrack(int idx, string& digits, string& combination,
                   vector<string>& ret) {
        if (idx == digits.size()) {
            ret.push_back(combination);
            return;
        }
        const vector<char>& letters = phone_map[digits[idx]];

        for (char c : letters) {
            combination.push_back(c);
            backtrack(idx + 1, digits, combination, ret);
            combination.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> ret = {};
        string combination;
        backtrack(0, digits, combination, ret);
        return ret;
    }
};



int main(int argc, char* argv[]){
    clock_t start = clock();

    Solution *sol = new Solution();
    vector<string> test_cases = {
        "23",
        "",
        "2",
        "246"
    };

    for(string test_case : test_cases){
    std::cout << sol->letterCombinations(test_case) << std::endl;
    }

    clock_t end = clock();
    double duration = (double)(end - start) / (__clock_t)1000;
    std::cout << std::endl << "Exicution Time: " << duration << " ms" << std::endl;
    return 0;
}