#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;

class Solution {
  public:
    std::unordered_map<char, int> rn = {{'I', 1},   {'V', 5},   {'X', 10},
                                        {'L', 50},  {'C', 100}, {'D', 500},
                                        {'M', 1000}};
    int romanToInt(string s) {
        int ret = 0;
        for (size_t i = 0; i < s.size() - 1; i++) {
            if (rn[s[i]] < rn[s[i + 1]]) {
                ret -= rn[s[i]];
            } else {
                ret += rn[s[i]];
            }
        }
        return ret + rn[s.back()];
    }
};

int main(int argc, char *argv[]) {
    Solution *sol = new Solution();
    vector<string> test_cases = {"III", "LVIII", "MCMXCIV"};

    for (string test_case : test_cases) {
        std::cout << sol->romanToInt(test_case) << std::endl;
    }
    return 0;
}