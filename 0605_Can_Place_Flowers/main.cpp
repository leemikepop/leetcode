#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            int count = 0;
            if (flowerbed.size() > 1) {
                if (flowerbed[0] == 0 && flowerbed[1] == 0) count++; flowerbed[0] = 1;
                if (flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == 0) count++; flowerbed[flowerbed.size()-1] = 1;
                for(int i = 1; i < flowerbed.size()-1; i++) {
                    if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                        count++;
                        flowerbed[i] = 1;
                    }
                }
                if (n <= count) return true;
                return false;
            }
            if(n == 0) return true;
            else if(flowerbed.size() == 1) if(flowerbed[0] == 0) return true;
            return false;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<pair<vector<int>,int>> test_cases = {
        {{1,0,0,0,1},1},
        {{1,0,0,0,1},2},
        {{0,0},0},
        {{1},0}
    };

    for(auto test_case : test_cases) {
        if(sol.canPlaceFlowers(test_case.first, test_case.second)) cout << "true" << endl;
        else cout << "false" << endl;
    }
}