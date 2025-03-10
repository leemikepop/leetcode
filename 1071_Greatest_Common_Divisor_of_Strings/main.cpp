#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string gcdOfStrings(string str1, string str2) {
            int gcd_size = gcd(str1.size(), str2.size());
            string result;
            if(str1 + str2 != str2 + str1) return "";
            else {
                for(int i = 0; i < gcd_size; i++) result += str1[i];
            }
            
            return result;
        }
    
        int gcd(int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        }
    };

int main(int argc, char* argv[]) {
    Solution* sol = new Solution();
    vector<pair<string,string>> test_cases = {
        {"ABCABC", "ABC"},
        {"ABABAB", "ABAB"},
        {"LEET", "CODE"},
        {"ABCDEF", "ABC"}
    };

    for(auto test_case : test_cases) {
        cout << sol->gcdOfStrings(test_case.first, test_case.second) << endl;
    }

    return 0;
}