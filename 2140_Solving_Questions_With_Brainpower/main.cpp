#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// choose or not choose
class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            vector<long long> result(questions.size(), 0);
            for(int i = questions.size()-1; i >= 0; i--) {
                int index = i + questions[i][1] + 1;
                if(index < questions.size() && i+1 < questions.size()) result[i] = max(questions[i][0] + result[index], result[i+1]);
                else if(i+1 < questions.size()) result[i] = max((long long)questions[i][0], result[i+1]);
                else result[i] = questions[i][0];
            }
            return result[0];
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    
    vector<vector<vector<int>>> test_cases = {
        {{3,2}, {4,3}, {4,4}, {2,5}},
        {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}},
        {{10, 1}, {20, 2}, {30, 3}, {40, 4}},
        {{5, 0}, {10, 1}, {15, 2}, {20, 3}}
    };
    
    for(auto& test_case : test_cases) {
        cout << sol.mostPoints(test_case) << endl;
    }
    
    return 0;
}