#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        void DFS(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
            visited[room] = true;
            for(int key : rooms[room]) {
                if(!visited[key]) {
                    DFS(key, rooms, visited);
                }
            }
        }
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            vector<bool> visited(rooms.size(), false);
            DFS(0, rooms, visited);
    
            for(bool visit : visited) {
                if(!visit) return false;
            }
    
            return true;
        }
    };

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> test_cases = {
        {{1}, {2}, {3}, {}},
        {{1,3}, {3,0,1}, {2}, {0}}
    };

    for(auto test_case : test_cases) {
        if(solution.canVisitAllRooms(test_case)) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}