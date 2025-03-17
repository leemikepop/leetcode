#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
            int maxCandies = *max_element(candies.begin(), candies.end());
            vector<bool> result;
            for(int i = 0; i < candies.size(); i++) {
                if((candies[i] + extraCandies) >= maxCandies) result.push_back(true);
                else result.push_back(false);
            }
            return result;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<pair<vector<int>, int>> test_cases = {
        {{2,3,5,1,3}, 3},
        {{4,2,1,1,2}, 1},
        {{12,1,12}, 10}
    };
    for(auto test_case : test_cases) {
        vector<bool> result = sol.kidsWithCandies(test_case.first, test_case.second);
        for(auto res : result) {
            if(res) cout << "true ";
            else cout << "false ";
        }
        cout << endl;
    }
    return 0;
}