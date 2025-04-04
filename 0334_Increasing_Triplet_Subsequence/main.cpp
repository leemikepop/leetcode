#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
    public:
        // slow
        bool increasingTriplet(vector<int>& nums) {
            int n = nums.size();
            vector<int> leftMin(n,0), rightMax(n,0);
    
            leftMin[0] = nums[0];
            for(int i = 1; i < n; i++) {
                leftMin[i] = min(leftMin[i-1], nums[i]);
            }
    
            rightMax[n-1] = nums[n-1];
            for(int i = n-2; i >= 0; i--) {
                rightMax[i] = max(rightMax[i+1], nums[i]);
            }
    
            for(int i = 0; i < n; i++) {
                if(nums[i] != leftMin[i] && nums[i] != rightMax[i]) return true;
            }
            return false;
        }

        //faster
        bool increasingTriplet_faster(vector<int>& nums) {
            int left = INT_MAX, mid = INT_MAX;
            for(int num : nums) {
                if(num <= left) left = num;
                else if(num <= mid) mid = num;
                else return true;
            }
            return false;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> test_cases = {
        {1,2,3,4,5},
        {5,4,3,2,1},
        {2,1,5,0,4,6},
        {20,100,10,12,5},
        {1,2}
    };
    cout << "Solution 1: " << endl;
    for(auto& test_case : test_cases) {
        if(sol.increasingTriplet(test_case)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    cout << endl << "Solution 2: " << endl;
    for(auto& test_case : test_cases) {
        if(sol.increasingTriplet_faster(test_case)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}