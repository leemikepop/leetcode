#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int pos = 0, neg = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] > 0) pos++;
                else if(nums[i] < 0) neg++;
            }
    
            return max(pos,neg);
        }
        int maximumCount_BS(vector<int>& nums) {
            int non_pos = binary_search(nums, 0);
            int pos = nums.size()-binary_search(nums, 1);
    
            return max(non_pos, pos);
        }
    
    private:
        int binary_search(vector<int>& nums, int target) {
            int left = 0, right = nums.size()-1, result = nums.size();
            int mid;
    
            while(left <= right) {
                mid = (left+right)/2;
                if(nums[mid] < target) {
                    left = mid+1;
                } else {
                    result = mid;
                    right = mid-1;
                }
            }
            
            return result;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> test_cases = {
        {-2,-1,-1,1,2,3},
        {-3,-2,-1,0,0,1,2},
        {5,20,66,1314},
        {0,0}
    };
    
    cout << "Time Complexity: O(n)" << endl;
    for(int i = 0; i < test_cases.size(); i++) {
        cout << sol.maximumCount(test_cases[i]) << endl;
    }

    cout << endl << "Time Complexity: O(logn)" << endl;
    for(int i = 0; i < test_cases.size(); i++) {
        cout << sol.maximumCount_BS(test_cases[i]) << endl;
    }

    return 0;
}