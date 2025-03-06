#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            vector<int> arr(grid.size()*grid[0].size(), 0);
    
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[0].size(); j++) {
                    arr[grid[i][j]-1]++; 
                }
            }
    
            vector<int> ans;
            for(int i = 0; i < grid.size()*grid[0].size(); i++) {
                if(arr[i] == 2) ans.push_back(i+1);
            }
            for(int i = 0; i < grid.size()*grid[0].size(); i++) {
                if(arr[i] == 0) ans.push_back(i+1);
            }
            return ans;
        }
    };

int main(int argv, char* argc[]) {
    Solution *sol = new Solution();
    vector<vector<vector<int>>> test_cases = {
        {{1,3},{2,2}},
        {{9,1,7},{8,9,2},{3,4,6}}
    };

    for(auto test_case : test_cases) {
        vector<int> result = sol->findMissingAndRepeatedValues(test_case);
        for(auto res : result) {
            cout << res << " ";
        }
        cout << endl;
    }

    return 0;
}