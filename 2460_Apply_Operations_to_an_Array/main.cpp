#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            for(int i = 0; i < nums.size()-1; i++) {
                if(nums[i] == nums[i+1]) {
                    nums[i] *= 2;
                    nums[i+1] = 0;
                    i++;
                }
            }
    
            vector<int> result(nums.size(),0);
            int index = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] != 0) {
                    result[index++] = nums[i];
                }
            }
    
            return result;
        }
    };

int main(int argc, char *argv[]) {
    Solution *sol = new Solution();
    vector<vector<int>> test_cases = {
        {1,2,2,1,1,0},
        {0,1},
        {3,3,3,3,3,3}
    };

    for(auto test_case : test_cases) {
        vector<int> result = sol->applyOperations(test_case);
        for(auto val : result) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}