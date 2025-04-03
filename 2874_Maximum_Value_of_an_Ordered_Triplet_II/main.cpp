#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            vector<long long> leftMax(n,0), rightMax(n,0);
    
            leftMax[0] = nums[0];
            for(int i = 1; i < n; i++) {
                leftMax[i] = max(leftMax[i-1], (long long)nums[i]);
            }
    
            rightMax[n-1] = nums[n-1];
            for(int i = n-2; i >= 0; i--) {
                rightMax[i] = max(rightMax[i+1], (long long)nums[i]);
            }
    
            long long maxValue = 0;
            for(int i = 1; i < n-1; i++) {
                long long cal = (leftMax[i-1] - (long long)nums[i]) * rightMax[i+1];
                if(maxValue < cal) maxValue = cal;
            }
            return maxValue;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> testCases = {
        {12,6,1,2,7},
        {1,10,3,4,19},
        {1,2,3},
    };
    for(auto& testCase : testCases) {
        cout << sol.maximumTripletValue(testCase) << endl;
    }
    return 0;
}