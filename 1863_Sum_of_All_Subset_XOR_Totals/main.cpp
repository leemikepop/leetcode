#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        // slow method O(2^n * n)
        int subsetXORSum(vector<int>& nums) {
            vector<vector<int>> sub = subset(nums);
            int sum = 0;
            for(auto s : sub) {
                int temp = 0;
                for(int n : s) {
                    temp ^= n;
                }
                sum += temp;
            }
            return sum;
        }
    
        vector<vector<int>> subset(vector<int>& nums) {
            vector<vector<int>> res = {{}};
            for(int num : nums) {
                int n = res.size();
                for(int i = 0; i < n; i++) {
                    vector<int> sub = res[i];
                    sub.push_back(num);
                    res.push_back(sub);
                }
            }
            return res;
        }

        int subsetXORSum_throughMath(vector<int>& nums) {
            int temp = 0;
            for(int num : nums) {
                temp |= num;
            }
            return temp * (1 << (nums.size()-1));
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> testCases = {
        {1, 3},
        {5, 1, 6},
        {3, 2, 1, 5}
    };

    cout << "Method 1: O(2^n * n)" << endl;
    for(auto& nums : testCases) {
        int result = sol.subsetXORSum(nums);
        cout << "Result: " << result << endl;
    }

    cout << endl << "Method 2: O(n)" << endl;
    for(auto& nums : testCases) {
        int result = sol.subsetXORSum_throughMath(nums);
        cout << "Result: " << result << endl;
    }
    return 0;
}