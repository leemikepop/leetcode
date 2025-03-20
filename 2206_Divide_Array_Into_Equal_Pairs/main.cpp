#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            vector<int> arr(501, 0);
            for(int i = 0; i < nums.size(); i++) {
                arr[nums[i]]++;
            }
            for(int i = 0; i < arr.size(); i++) {
                if(arr[i]%2 != 0) return false;
            }
            return true;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> test_cases = {
        {3,2,3,3,2,3},
        {1,2,3,4}
    };
    
    for(auto test_case : test_cases) {
        if(sol.divideArray(test_case)) cout << "true" << endl;
        else cout << "false" << endl;
    }
}