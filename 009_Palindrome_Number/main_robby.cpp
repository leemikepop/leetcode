#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        auto str = to_string(x); //convert integer to string
        for(int i = 0; i < (str.size()/2); i++) {
            // cout << str[i] << endl << str[str.size()-1-i] << endl;
            if(str[i] != str[str.size()-1-i]) {
                return false; //not palindrome
            }
        }
        return true; //palindrome
    }
};

int main(int argc, char* argv[]){
    Solution *sol = new Solution();
    vector<int> test_cases = {
        1234567899,
        121,
        -121,
        10,
        -2147447412,
        2147483647
    };

    for(int test_case : test_cases){
        std::cout << sol->isPalindrome(test_case) << std::endl;
    }
    return 0;
}