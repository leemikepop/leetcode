#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> parent;
    vector<int> rank;
    vector<int> node_count;
    vector<int> edge_count;
private:
    void makeSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        node_count.resize(n, 1);
        edge_count.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return;
        if(rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            node_count[rootX] += node_count[rootY];
            // edge_count[rootX] += edge_count[rootY] + 1;
        } else if(rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            node_count[rootY] += node_count[rootX];
            // edge_count[rootY] += edge_count[rootX] + 1;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
            node_count[rootX] += node_count[rootY];
            // edge_count[rootX] += edge_count[rootY] + 1;
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        makeSet(n);
        for (auto edge : edges) {
            if(find(edge[0]) != find(edge[1])) {
                Union(edge[0], edge[1]);
            }
        }
        for (auto edge : edges) {
            edge_count[find(edge[0])] ++;
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(find(i) == i) {
                int n = node_count[i];
                if(edge_count[i] == (n * (n-1)) / 2) count++;
            }
        }

        return count;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<int, vector<vector<int>>>> test_cases = {
        {6, {{0,1},{0,2},{1,2},{3,4}}},
        {6, {{0,1},{1,2},{2,3},{3,4},{4,5}}},
        {5, {{0,1},{1,2},{2,3},{3,4},{4,0}}},
        {5, {{1,2},{3,4},{1,4},{2,3},{1,3},{2,4}}}
    };

    for(auto test_case : test_cases) {
        cout << solution.countCompleteComponents(test_case.first, test_case.second) << endl;
    }
    return 0;
}