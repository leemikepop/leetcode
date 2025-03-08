/*
https://leetcode.com/problems/valid-parentheses/description/
*/
#include <ctime>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution {
  public:
    bool isValid(string s) {
        stack<char> sk;
        for (const char &c : s) {
            if (c == '(' || c == '[' || c == '{') {
                sk.push(c);
            } else {
                if (sk.empty() || (c == ')' && sk.top() != '(') ||
                    (c == ']' && sk.top() != '[') ||
                    (c == '}' && sk.top() != '{')) {
                    return false;
                }
                sk.pop();
            }
        }
        return sk.empty();
    }
};

int main(int argc, char *argv[]) {
    clock_t start = clock();

    Solution *sol = new Solution();
    vector<string> test_cases = {"()", "()[]{}", "(]"};

    for (string test_case : test_cases) {
        std::cout << sol->isValid(test_case) << std::endl;
    }

    clock_t end = clock();
    double duration = (double)(end - start) / (__clock_t)1000;
    std::cout << std::endl
              << "Exicution Time: " << duration << " ms" << std::endl;
    return 0;
}