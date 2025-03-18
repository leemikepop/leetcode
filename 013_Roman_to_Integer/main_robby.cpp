#include <iostream>
#include <vector>

using namespace std;;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0; //store the result
        int count_i = 0; //count the number of i
        
    }
};

int main(int argc, char *argv[]) {
    Solution *sol = new Solution();
    vector<string> test_cases = {"III", "LVIII", "MCMXCIV"};

    for (string test_case : test_cases) {
        std::cout << sol->romanToInt(test_case) << std::endl;
    }
    return 0;
}