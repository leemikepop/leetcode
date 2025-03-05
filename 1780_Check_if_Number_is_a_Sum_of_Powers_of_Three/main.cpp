#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            if(n == 0) return false;
            string tenary = "";
            while(n > 0) {
                tenary += to_string(n%3);
                n/=3;
            }
            for(int i = 0; i < tenary.size(); i++) {
                if(tenary[i] != '0' && tenary[i] != '1') return false;
            }
    
            return true;
        }

        bool checkPowersOfThree2(int n) {
            while(n > 0) {
                if(n % 3 == 2) return false;
                n/=3;
            }
    
            return true;
        }
    };

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> test_cases = {12, 91, 21, 1, 0};

    cout << "Solution 1" << endl;

    for(int i = 0; i < test_cases.size(); i++) {
        if(solution.checkPowersOfThree(test_cases[i])) cout << "true" << endl;
        else cout << "false" << endl;
    }

    cout << endl << "Solution 2" << endl;

    for(int i = 0; i < test_cases.size(); i++) {
        if(solution.checkPowersOfThree2(test_cases[i])) cout << "true" << endl;
        else cout << "false" << endl;
    }

    return 0;
}