#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.size();
        bool** dp = new bool*[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new bool[n];
        }

        int start,len;  //for s.substr(start, len)

        for(int l = 0; l < n; l++){ //l = level
            for(int i = 0; i < n - l; i++){
                int j = i + l;
                if(s[i]==s[j] && (j-i<=1 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    start = i;
                    len = j-i+1;
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return s.substr(start, len);
    }
};

int main(int argc, char* argv[]){
    Solution* sol = new Solution();
    std::vector<std::string> test_cases = {"babad", "cbbd"};

    for(std::string s : test_cases){
        std::cout << sol->longestPalindrome(s) << std::endl;
    }

    return 0;
}