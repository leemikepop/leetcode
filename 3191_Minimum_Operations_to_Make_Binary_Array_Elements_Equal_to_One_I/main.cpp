#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int count = 0;
            for(int left = 0; left < nums.size()-2; left++) {
                if(!truth(nums[left])) {
                    nums[left] = 1;
                    if(truth(nums[left+1])) nums[left+1] = 0;
                    else nums[left+1] = 1;
                    if(truth(nums[left+2])) nums[left+2] = 0;
                    else nums[left+2] = 1;
                    count++;
                }
            }
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) return -1;
            }
            return count;
        }
        int minOperations_xor(vector<int>& nums) {
            int count = 0;
            for(int left = 0; left < nums.size()-2; left++) {
                if(nums[left] == 0) {
                    nums[left] ^= 1;
                    nums[left+1] ^= 1;
                    nums[left+2] ^= 1; 
                    count++;
                }
            }
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) return -1;
            }
            return count;
        }
    private:
        bool truth(int num) {
            if(num == 0) return false;
            return true;
        }
    };

int  main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> test_cases = {
        {0,1,1,1,0,0},
        {0,1,1,1},
    };

    cout << "First Solution: " << endl;
    for(auto test_case : test_cases) {
        cout << sol.minOperations(test_case) << endl;
    }

    cout << endl << "Second Solution (XOR): " << endl;
    for(auto test_case : test_cases) {
        cout << sol.minOperations_xor(test_case) << endl;
    }

    return 0;
}