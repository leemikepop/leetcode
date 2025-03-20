#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int product = 1;
            vector<int> copy = nums;
            for(int i = 0; i < nums.size(); i++) {
                product *= nums[i];
            }
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] != 0) nums[i] = product/nums[i];
                else {
                    int inner_product = 1;
                    for(int j = 0; j < nums.size(); j++) {
                        if(j != i) inner_product *= copy[j];
                    }
                    nums[i] = inner_product;
                }
            }
            return nums;
        }

        vector<int> productExceptSelf_fast(vector<int>& nums) {
            vector<int> output(nums.size(), 1);
            int left = 1, right = 1;
    
            for(int i = 0; i < nums.size(); i++) {
                output[i] *= left;
                left *= nums[i];
            }
    
            for(int i = nums.size()-1; i >= 0; i--) {
                output[i] *= right;
                right *= nums[i];
            }
    
            return output;
        }
    };

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> test_cases = {
        {1,2,3,4},
        {-1,1,0,-3,3}
    };
    
    cout << "Solution 1:" << endl;
    for(auto test_case : test_cases) {
        vector<int> res = solution.productExceptSelf(test_case);
        for(auto r : res) {
            cout << r << " ";
        }
        cout << endl;
    }

    cout << endl << "Solution 2 (O(n)):" << endl;
    for(auto test_case : test_cases) {
        vector<int> res = solution.productExceptSelf_fast(test_case);
        for(auto r : res) {
            cout << r << " ";
        }
        cout << endl;
    }

    return 0;
}