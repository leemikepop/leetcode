#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pre_sum = 0, post_sum = 0;
        for(int i = 1; i < nums.size(); i++) post_sum += nums[i];
        for(int i = 0; i < nums.size()-1; i++) {
            if(pre_sum == post_sum) return i;
            pre_sum += nums[i];
            post_sum -= nums[i+1];
        }

        if(pre_sum == 0) return nums.size()-1;
        return -1;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> test_cases = {
        {1, 7, 3, 6, 5, 6},
        {1, 2, 3},
        {2, 1, -1},
        {0, 0, 0, 0, 1}
    };

    for(auto& test_case : test_cases) {
        cout << solution.pivotIndex(test_case) << endl;
    }

    return 0;
}