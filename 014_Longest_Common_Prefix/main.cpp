#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::min;
using std::string;
using std::vector;

class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret = "";
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs[strs.size() - 1];
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                return ret;
            }
            ret += first[i];
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution *sol = new Solution();
    vector<vector<string>> test_cases = {
        {"flower", "flow", "flight"},
        {"dog", "racecar", "car"},
        {"abcd", "abccc", "abdec"},
        {"geeksforgeeks", "geeks", "geek", "geezer"},
    };

    for (vector<string> test_case : test_cases) {
        std::cout << sol->longestCommonPrefix(test_case) << std::endl;
    }
    return 0;
}