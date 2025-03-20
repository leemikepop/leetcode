#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int left = 0;
            for(int right = 0; right < t.size(); right++) {
                if(s[left] == t[right]) left++;
            }
            if(left == s.size()) return true;
            return false;
        }
    };

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<string, string>> test_cases = {
        {"abc", "ahbgdc"},
        {"axc", "ahbgdc"},
        {"", "ahbgdc"},
        {"abc", ""}
    };

    for(auto test_case : test_cases) {
        if(solution.isSubsequence(test_case.first, test_case.second)) cout << "true" << endl;
        else cout << "false" << endl;
    }
}