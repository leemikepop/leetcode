#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::max;
using std::min;
using std::string;
using std::vector;

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int area = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            area = max(area, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return area;
    }
};

int main(int argc, char *argv[]) {
    Solution *sol = new Solution();
    vector<vector<int>> test_cases = {vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7},
                                      vector<int>{1, 1}};

    for (vector<int> test_case : test_cases) {
        std::cout << sol->maxArea(test_case) << std::endl;
    }
    return 0;
}