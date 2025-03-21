#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            double max_average = 0, sum = 0;
            int left = 0, right = k-1;
            for(int i = 0; i <= right; i++) sum += nums[i];
            max_average = round(sum/k * 1e5) / 1e5;
            left++;
            right++;
            while(right < nums.size()) {
                sum -= nums[left-1];
                sum += nums[right];
                max_average = max(max_average, round(sum/k * 1e5) / 1e5); 
                left++;
                right++;
            }
            return max_average;
        }

        double findMaxAverage_clear(vector<int>& nums, int k) {
            double max_sum = 0, sum = 0;
            for(int i = 0; i < k; i++) sum += nums[i];
            max_sum = sum;
            for(int i = 1; i <= nums.size()-k; i++) {
                sum += nums[i+k-1]-nums[i-1];
                if(max_sum < sum) max_sum = sum;
            }
            return max_sum/k;
        }
    };

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, int>> test_cases = {
        {{1,12,-5,-6,50,3}, 4},
        {{5}, 1},
        {{1,2,3,4,5,6,7,8,9,10}, 5}
    };

    cout << "Solution 1:" << endl;
    for(auto test_case : test_cases) {
        cout << solution.findMaxAverage(test_case.first, test_case.second) << endl;
    }

    cout << endl << "Solution 2:" << endl;
    for(auto test_case : test_cases) {
        cout << solution.findMaxAverage_clear(test_case.first, test_case.second) << endl;
    }
    return 0;
}