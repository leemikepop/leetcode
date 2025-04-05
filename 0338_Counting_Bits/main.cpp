#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int> result(n+1, 0);
            int sub = 1;
            for(int i = 1; i <= n; i++) {
                if(sub * 2 == i) sub*=2;
                result[i] = result[i-sub] + 1;
            }
            return result;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<int> testCases = {2, 5, 10};
    for(auto& n : testCases) {
        vector<int> result = sol.countBits(n);
        for(int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}