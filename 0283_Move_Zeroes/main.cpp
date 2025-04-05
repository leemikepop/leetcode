#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            for(int i = nums.size()-2; i >= 0; i--) {
                if(nums[i] == 0) {
                    for(int j = i; j < nums.size()-1; j++) {
                        swap(nums[j], nums[j+1]);
                    }
                }
            }
        }

        void moveZeroes_fast(vector<int>& nums) {
            int left = 0, right = 0;
            while(left < nums.size() && right < nums.size()) {
                while(nums[left] != 0) {
                    left++;
                    if(left >= nums.size()) break;
                }
                while(nums[right] == 0) {
                    right++;
                    if(right >= nums.size()) break;
                }
                if((left < nums.size() && right < nums.size()) && left < right) {
                    swap(nums[left], nums[right]);
                    left++;
                    right++;
                } else {
                    right++;
                }
            }
        }

        void moveZeroes_perfect(vector<int>& nums) {
            int left = 0;
    
            for(int right = 0; right < nums.size(); right++) {
                if(nums[right] != 0) {
                    swap(nums[left], nums[right]);
                    left++;
                }
            }
        }
    };

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> test_cases = {
        {0,1,0,3,12},
        {0},
        {1},
        {0,0,1},
        {1,0},
        {1,0,1}
    };

    cout << "Solution 1 (O(n^2)):" << endl;
    for(auto test_case : test_cases) {
        solution.moveZeroes(test_case);
        for(auto r : test_case) {
            cout << r << " ";
        }
        cout << endl;
    }

    cout << endl << "Solution 2 (O(n)):" << endl;
    for(auto test_case : test_cases) {
        solution.moveZeroes_fast(test_case);
        for(auto r : test_case) {
            cout << r << " ";
        }
        cout << endl;
    }

    cout << endl << "Solution 3 (O(n)) Real Two Pointer:" << endl;
    for(auto test_case : test_cases) {
        solution.moveZeroes_perfect(test_case);
        for(auto r : test_case) {
            cout << r << " ";
        }
        cout << endl;
    }

    return 0;
}