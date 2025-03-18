#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int low = 1, high = max(candies), ans = 0;
            int mid;
            long long sum;
            while(low <= high) {
                mid = low + (high-low)/2;
                sum = 0;
                for(int i = 0; i < candies.size(); i++) {
                    sum += candies[i]/mid;
                }
                if(sum >= k) {
                    low = mid + 1;
                    ans = mid;
                }
                else high = mid - 1;
            }
            return ans;
        }

    private:
        int max(vector<int>& candies) {
            int max = candies[0];
            for(int i = 0; i < candies.size(); i++) {
                if(max < candies[i]) max = candies[i];
            }
            return max;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<pair<vector<int>, int>> test_cases = {
        {{5,8,6}, 3},
        {{2,5}, 11},
        {{4,7,5}, 16},
        {{5,6,4,10,10,1,1,2,2,2},9},
        {{1,2,6,8,6,7,3,5,2,5}, 3}
    };

    for(auto test_case : test_cases) {
        cout << sol.maximumCandies(test_case.first, test_case.second) << endl;
    }
}