#include <iostream>
#include <stack>
#include <vector>
#include <climits>

class Solution {
public:
    int reverse(int x) {        
        int ret = 0;
        int up = INT_MAX/10;
        int low = INT_MIN/10;
        while(x){
            if(ret > up || ret < low) return 0;
            ret = ret*10 + x%10;
            x /= 10;
        }
        return ret;
    }
};

int main(int argc, char* argv[]){
    Solution *sol = new Solution();
    std::vector<int> test_cases = {
        2147483647,
        1463847412,
        1534236469,
        123,
        -123,
        120,
    };

    for(int test_case : test_cases){
        std::cout << sol->reverse(test_case) << std::endl;
    }
    return 0;
}