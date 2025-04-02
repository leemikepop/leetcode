#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long max = 0;
            for(int i = 0; i < nums.size()-2; i++) {
                for(int j = i+1; j < nums.size()-1; j++) {
                    for(int k = j+1; k < nums.size(); k++) {
                        long long cal = ((long long)nums[i]-(long long)nums[j])*(long long)nums[k];
                        if(max < cal) max = cal;
                    }
                }
            }
            return max;
        }

        long long maximumTripletValue_faster(vector<int>& nums) {
            int n = nums.size();
            vector<int> leftMax(n, 0), rightMax(n, 0);
    
            leftMax[0] = nums[0];
            for(int i = 1; i < nums.size(); i++) {
                leftMax[i] = max(leftMax[i-1], nums[i]);
            }
    
            rightMax[n-1] = nums[n-1];
            for(int i = n-2; i >= 0; i--) {
                rightMax[i] = max(rightMax[i+1], nums[i]);
            }
    
            long long maxValue = 0;
            for(int i = 1; i < n-1; i++) {
                long long cal = static_cast<long long>(leftMax[i-1] - nums[i])* rightMax[i+1];
                if(maxValue < cal) maxValue = cal;
            }
    
            return maxValue;
        }
    };

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> nums = {
        {1,2,3},
        {12,6,1,2,7},
        {1,10,3,4,19},
    };

    cout << "O(n^3) solution:" << endl;
    for(auto& v : nums) {
        cout << "nums: ";
        for(auto& n : v) {
            cout << n << " ";
        }
        cout << endl;
        cout << "max: " << s.maximumTripletValue(v) << endl << endl;
    }

    cout << endl << endl << "O(n) solution:" << endl;
    for(auto& v : nums) {
        cout << "nums: ";
        for(auto& n : v) {
            cout << n << " ";
        }
        cout << endl;
        cout << "max: " << s.maximumTripletValue_faster(v) << endl << endl;
    }
    return 0;
}