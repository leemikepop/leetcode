#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        // Using O(n^2) will get TLE
        int maxArea(vector<int>& height) {
            int left = 0, right = height.size()-1, max_area = 0;
            while(left < right) {
                max_area = max(max_area, min(height[left], height[right])*(right-left));
                if(height[left] < height[right]) left++;
                else right--;
            }
            return max_area;
        }
    };

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> test_cases = {
        {1,8,6,2,5,4,8,3,7},
        {1,1},
        {4,3,2,1,4},
        {1,2,1}
    };

    for(auto test_case : test_cases) {
        cout << solution.maxArea(test_case) << endl;
    }

    return 0;
}