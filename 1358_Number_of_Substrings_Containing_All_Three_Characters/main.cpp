#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int numberOfSubstrings(string s) {
            if (s.size() < 3) return 0;
            int count = 0;
            int arr[128] = {0};
            bool has = false;
            for(int left = 0; left < s.size()-2; left++) {
                has = false;
                fill(arr, arr + 128, 0); 
                for(int right = left+2; right < s.size(); right++) {
                    int i = left;
                    if(has) {
                        count += s.size()-right;
                        right += s.size()-right;
                    } else {
                        while(i <= right) {
                            arr[s[i]]++;
                            i++;
                        }
                        if(arr['a'] > 0 && arr['b'] > 0 && arr['c'] > 0) {
                            has = true;
                            count++;
                        }
                    }
                }
            }
            return count;
        }

        int numberOfSubstrings_fast(string s) {
            if (s.size() < 3) return 0;
            int count = 0;
            int arr[128] = {0};
            int right = 0;
            for(int left = 0; left < s.size()-2; left++) {
                if(left > 0) arr[s[left-1]]--;
                while((arr['a'] < 1 || arr['b'] < 1 || arr['c'] < 1) && right < s.size()) {
                    arr[s[right]]++;
                    right++;
                }
                if(arr['a'] > 0 && arr['b'] > 0 && arr['c'] > 0) {
                    count += s.size()-right+1;
                }
            }
            return count;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<string> test_cases = {
        "abcabc",
        "aaacb",
        "abc"
    };

    cout << "Time Complexity O(n^2)" << endl;
    for(auto test_case : test_cases) {
        cout << sol.numberOfSubstrings(test_case) << endl;
    }

    cout << endl << "Time Complexity O(n)" << endl;
    for(auto test_case : test_cases) {
        cout << sol.numberOfSubstrings_fast(test_case) << endl;
    }
    return 0;
}