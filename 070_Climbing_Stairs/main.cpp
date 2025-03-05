#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int climbStairs(int n) {
            if(n == 0) return 0;
            else if(n == 1) return 1;
            int arr[n];
            arr[0] = 1;
            arr[1] = 2;
            for(int i = 2; i < n; i++) {
                arr[i] = arr[i-1] + arr[i-2];
            }
    
            return arr[n-1];
        }
    };

int main(int argc, char *argv[]) {
    Solution *sol = new Solution();
    vector<int> test_cases = {
        2, 3, 4
    };

    for(auto test_case : test_cases) {
        int result = sol->climbStairs(test_case);
        cout << result << endl;
    }

    return 0;
}