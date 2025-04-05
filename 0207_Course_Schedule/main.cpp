#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        bool DFS(vector<int>& visit, vector<vector<int>>& adj, int node) {
            visit[node] = 1;
            for(auto& n : adj[node]) {
                if(visit[n] == 0) if(!DFS(visit, adj, n)) return false;
                else if(visit[n] == 1) return false;                 
            }
            visit[node] = 2;
            return true;
        }
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int> visit(numCourses, 0);
            vector<vector<int>> adj(numCourses);
            for(auto& prerequisties : prerequisites) {
                adj[prerequisties[1]].push_back(prerequisties[0]);
            }
            for(int i = 0; i < visit.size(); i++) {
                if(visit[i] == 0) {
                    if(!DFS(visit, adj, i)) return false;
                }
            }
            return true;
        }
    };

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<int, vector<vector<int>>>> test_cases = {
        // {2, {{1,0}}},
        {2, {{1,0},{0,1}}},
        // {3, {{1,0},{2,1}}},
        // {3, {{1,0},{2,1},{0,2}}},
        // {20, {{0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4}}},
        // {5, {{1,4},{2,4},{3,1},{3,2}}}
    };

    for(auto& test_case : test_cases) {
        if(solution.canFinish(test_case.first, test_case.second)) cout << "true" << endl;
        else cout << "false" << endl;
    }

    return 0;
}