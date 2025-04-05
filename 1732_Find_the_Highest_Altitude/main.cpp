#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int largestAltitude(vector<int>& gain) {
            vector<int> altitude(gain.size()+1, 0);
            int max = 0;
            for(int i = 1; i < altitude.size(); i++) {
                altitude[i] = altitude[i-1] + gain[i-1];
                if(max < altitude[i]) max = altitude[i];
            }
            return max;
        }
    };

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> test_cases = {
        {-5, 1, 5, 0, -7},
        {-4, -3, -2, -1, 4, 3, 2}
    };

    for(auto gain : test_cases) {
        cout << solution.largestAltitude(gain) << endl;
    }
}