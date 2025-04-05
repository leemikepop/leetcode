#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
        // MLE
        string removeStars_MLE(string s) {
            stack<char> store;
            string result = "";
            for(int i = 0; i < s.size(); i++) {
                if(s[i] != '*') store.push(s[i]);
                else store.pop();
            }
            int size = store.size();
            for(int i = 0; i < size; i++) {
                result = store.top() + result;
                store.pop();
            }
            return result;
        }

        string removeStars(string s) {
            string result = "";
            for(int i = 0; i < s.size(); i++) {
                if(s[i] != '*') result += s[i];
                else result.pop_back();
            }
            return result;
        }
    };

int main(int argc, char** argv) {
    Solution s;
    vector<string> testCases = {
        "leet**cod*e",
        "erase*****",
        "a*b*c*d*e*f*",
        "abcde",
    };

    for(auto& testCase : testCases) {
        cout << "Input: " << testCase << endl;
        cout << "Output: " << s.removeStars(testCase) << endl;
    }

    return 0;
}