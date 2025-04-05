#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int findJudge(int n, vector<vector<int>>& trust) {
            vector<int> indegree(n+1, 0), outdegree(n+1, 0);
            for(int i = 0; i < trust.size(); i++) {
                indegree[trust[i][1]]++;
                outdegree[trust[i][0]]++;
            }
            for(int i = 1; i < indegree.size(); i++) {
                if(indegree[i] == n-1 && outdegree[i] == 0) return i;
            }
            return -1;
        }
    };

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<int, vector<vector<int>>>> test_cases = {
        {2, {{1,2}}},
        {3, {{1,3},{2,3}}},
        {3, {{1,3},{2,3},{3,1}}}
    };

    for(auto test_case : test_cases) {
        cout << solution.findJudge(test_case.first, test_case.second) << endl;
    }
    return 0;
}