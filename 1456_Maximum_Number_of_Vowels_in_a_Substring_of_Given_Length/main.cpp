#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int maxVowels(string s, int k) {
        int count = 0;
        for(int i = 0; i < k; i++) {
            if(isVowel(s[i])) count++;
        }

        int max = count;
        for(int left = 1; left < s.size()-k+1; left++) {
            if(isVowel(s[left-1])) count--;
            if(isVowel(s[left+k-1])) count++;
            if(count > max) max = count;
        }

        return max;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<string, int>> test_cases = {
        {"abciiidef", 3},
        {"aeiou", 2},
        {"leetcode", 3},
        {"rhythms", 4},
        {"tryhard", 4}
    };

    for(auto& test_case : test_cases) {
        cout << solution.maxVowels(test_case.first, test_case.second) << endl;
    }

    return 0;
}