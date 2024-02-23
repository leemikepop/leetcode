#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int max_length = 0;
        int left = 0;

        for(int i = 0; i < s.length(); i++){
            left = updateSubsequenceLeft(s, left, i, s[i]);
            max_length = std::max(i - left + 1, max_length);
        }
        return max_length;
    }
    int updateSubsequenceLeft(std::string &s, int left, int right, char a){
        for(int i = left; i < right; i++){
            if(a==s[i]){
                return i+1;
            }
        }
        return left;
    }
};

int main(int argc, char* argv[]){
    std::string t1 = "abcabcbb";
    std::string t2 = "bbbbb";
    std::string t3 = "pwwkew";

    Solution *s = new Solution();
    int ret;
    ret = s->lengthOfLongestSubstring(t1);
    std::cout << ret << std::endl;
    ret = s->lengthOfLongestSubstring(t2);
    std::cout << ret << std::endl;
    ret = s->lengthOfLongestSubstring(t3);
    std::cout << ret << std::endl;


    return 0;
}