#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            int i = 0, j = 0;
            string result;
            while(i < word1.size() && j < word2.size()) {
                if(i <= j) result += word1[i++];
                else result += word2[j++];
            }
            while(i < word1.size()) result += word1[i++];
            while(j < word2.size()) result += word2[j++];
    
            return result;
        }

        string mergeAlternately2(string word1, string word2) {
            string result;
            int i = 0;
            while(i < word1.size() || i < word2.size()) {
                if(i < word1.size()) result += word1[i];
                if(i < word2.size()) result += word2[i];
                i++;
            }

            return result;
        }
    };

int main(int argc, char* argv[]) {
    Solution* sol = new Solution();
    vector<pair<string,string>> test_cases = {
        {"abc", "pqr"},
        {"ab", "pqrs"},
        {"abcd", "pq"},
        {"", "pqrs"}
    };

    cout << "Solution 1" << endl;

    for(auto test_case : test_cases) {
        cout << sol->mergeAlternately(test_case.first, test_case.second) << endl;
    }

    cout << endl << "Solution 2" << endl;

    for(auto test_case : test_cases) {
        cout << sol->mergeAlternately2(test_case.first, test_case.second) << endl;
    }

    return 0;
}