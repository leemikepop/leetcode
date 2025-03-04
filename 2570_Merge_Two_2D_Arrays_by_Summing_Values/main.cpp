#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int i = 0, j = 0, index = 0;
            vector<vector<int>> result;
    
            while(i < nums1.size() && j < nums2.size()) {
                if(nums1[i][0] == nums2[j][0]) {
                    result.push_back({nums1[i][0], nums1[i][1]+nums2[j][1]});
                    i++;
                    j++;
                } else if(nums1[i][0] < nums2[j][0]) {
                    result.push_back(nums1[i++]);
                } else {
                    result.push_back(nums2[j++]);
                }
            }
            while(i<nums1.size()) result.push_back(nums1[i++]);
            while(j<nums2.size()) result.push_back(nums2[j++]);
    
            return result;
        }
    };

int main(int argc, char* argv[]) {
    Solution* sol = new Solution();
    vector<vector<vector<vector<int>>>> test_cases = {
        {{{1,2},{2,3},{4,5}}, {{1,4},{3,2},{4,1}}},
        {{{1,3},{2,2},{3,1}}, {{1,2},{2,3},{3,2}}},
        {{{2,4},{3,6},{5,5}}, {{1,3},{4,3}}},
    };

    for(auto i : test_cases) {
        vector<vector<int>> result = sol->mergeArrays(i[0], i[1]);
        for(auto j : result) {
            cout << j[0] << "," << j[1] << " ";
        }
        cout << endl;
    }
}