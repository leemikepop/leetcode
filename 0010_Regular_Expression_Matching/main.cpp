#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>		//pair

using std::vector;
using std::string;
using std::pair;

class Solution1 {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n + 1][m + 1];
        memset(dp, false, sizeof(dp));
        /*s="" p=""*/
        dp[0][0] = true;

        /*
            s = ""
            p = "a*b*c*" any char followd with `*`
            Use length as index: s[0]=λ, p[0]=λ, p[1]='a', p[2]='*'.
            In this case:
            s\p   λ   a   *   b   *   c   *  
             λ  | T | F | T | F | T | F | T |
        */
        for(int j = 1; j <= m; j++){
            dp[0][j] = p[j-1]=='*' && dp[0][j-2];
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                /*
                    s = "ab"
                    p = ".b*"
                    In this case:
                    s\p   λ   .   b   *
                     λ  | T | F | F | F |
                     a  | F | T | F | T |
                     b  | F | T | T | T |
                */
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1]=='*'){
                    if(p[j-2]!=s[i-1] && p[j-2]!='.'){
                        dp[i][j] = dp[i][j-2];
                    }else{
                        dp[i][j] = dp[i][j-2] || dp[i-1][j];    
                    }
                }
            }
        }
        return dp[n][m];
    }
};
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n + 1][m + 1];
        memset(dp, false, sizeof(dp));
        /*s="" p=""*/
        dp[0][0] = true;

        /*
            s = ""
            p = "a*b*c*" any char followd with `*`
            Use length as index: s[0]=λ, p[0]=λ, p[1]='a', p[2]='*'.
            In this case:
            s\p   λ   a   *   b   *   c   *  
             λ  | T | F | T | F | T | F | T |
        */
        /*
            s = "ab"
            p = ".b*"
            In this case:
            s\p   λ   .   b   *
             λ  | T | F | F | F |
             a  | F | T | F | T |
             b  | F | T | T | ? |
        */
        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[j-1]=='*'){//
                    dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
                }else{ //    i==0->F
                    dp[i][j] = i>0 && dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
                }
            }
        }
        return dp[n][m];
    }
};

int main(int argc, char* argv[]){
    Solution *sol = new Solution();
    vector<pair<string,string>> test_cases = {
        std::make_pair("aa", "a"),
        std::make_pair("aa", "a*"),
        std::make_pair("ab", ".*"),
        std::make_pair("a", "1"),
        std::make_pair("mississippi", "mis*is*p*."),
        std::make_pair("mississippi", "mis*is*ip*."),
    };

    for(pair<string,string> test_case : test_cases){
        std::cout << sol->isMatch(test_case.first, test_case.second) << std::endl;
    }
    return 0;
}