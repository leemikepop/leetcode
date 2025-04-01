#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> nums1Set(nums1.begin(), nums1.end());
            unordered_set<int> nums2Set(nums2.begin(), nums2.end());
            unordered_set<int> result1Set, result2Set;
    
            for(int num : nums1) {
                if(nums2Set.count(num) == 0) {
                    result1Set.insert(num);
                }
            }
    
            for(int num : nums2) {
                if(nums1Set.count(num) == 0) {
                    result2Set.insert(num);
                }
            }
    
            vector<int> result1(result1Set.begin(), result1Set.end());
            vector<int> result2(result2Set.begin(), result2Set.end());
    
            return {result1, result2};
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    
    vector<pair<vector<int>, vector<int>>> test_cases = {
        {{1, 2, 3}, {2, 4, 6}},
        {{1, 2, 3, 3}, {1, 1, 2, 2}},
        {{1, 2, 3}, {1, 2, 3}},
        {{1, 2, 3}, {4, 5, 6}},
        {{1}, {2}}
    };
    
    for(auto& test_case : test_cases) {
        auto result = sol.findDifference(test_case.first, test_case.second);
        cout << "[";
        for(auto& vec : result) {
            cout << "[";
            for(int i = 0; i < vec.size(); i++) {
                cout << vec[i] << (i < vec.size() - 1 ? "," : "");
            }
            cout << "]";
        }
        cout << "]" << endl;
    }
    
    return 0;
}