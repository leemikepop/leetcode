#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int count = 0;
            for(int i = 0; i < blocks.size(); i++) {
                if(blocks[i] == 'B') {
                    count ++;
                    if(count == k) return 0;
                } else {
                    count = 0;
                }
            }
            int min = 1000;
            for(int i = 0; i <= blocks.size()-k; i++) {
                count = 0;
                for(int j = i; j < i+k; j++) {
                    if(blocks[j] == 'W') count++;
                }
                if(min > count) min = count;
            }
    
            return min;
        }
    };

int main(int argc, char* argv[]) {
    Solution* sol = new Solution();
    vector<pair<string,int>> test_cases = {
        {"BBBWW",3},
        {"BBWBW",3},
        {"BWBBWWBBBWBWWWBWWBBWBWBBWBB",11},
        {"BWWWBB",6}
    };
    for(auto test_case : test_cases) {
        cout << sol->minimumRecolors(test_case.first, test_case.second) << endl;
    }


    return 0;
}