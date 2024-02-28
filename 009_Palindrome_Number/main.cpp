#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long r_x = 0;   //overcome overflow
        long copy_x = (long)x;
        while(x){
            r_x = r_x*10 + x%10;
            x /= 10;
        }
        return r_x==copy_x;
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