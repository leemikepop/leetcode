#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            istringstream ss(s);
            string word;
            vector<string> words;
    
            while(ss >> word) {
                words.push_back(word);
            }
    
            string result = "";
            for(int i = words.size()-1; i > 0; i--) {
                result += words[i] + " ";
            }
            result += words[0];
    
            return result;
        }
        string reverseWords_fast(string s) {
            int left  = s.size()-1, right = s.size()-1;
            string result;
            while(left >= 0 && right >= 0) {
                while(s[right] == ' '&& right > 0) right--;
                while((s[left] != ' ' && left >= 0) || left >= right) left--;
                result += s.substr(left+1,right-left+1);
                left--;
                right -= right-left+1;
                if(right < 0 && left < 0) break;
                else result += " ";
            }
            return result;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<string> test_cases = {
        "the sky is blue",
        "  hello world  ",
        "a good   example"
    };

    for(auto test_case : test_cases) {
        cout << sol.reverseWords_fast(test_case) << endl;
    }

    return 0;
}