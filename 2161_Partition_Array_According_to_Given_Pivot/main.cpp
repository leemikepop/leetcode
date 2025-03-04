#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int left = 0;
            int right = nums.size()-1;
            vector<int> result(nums.size(),0);

            for(int i = 0, j = nums.size()-1; i < nums.size(); ++i, --j) {
                if(nums[i] < pivot) {
                    result[left] = nums[i];
                    left++;
                }
                if(nums[j] > pivot) {
                    result[right] = nums[j];
                    right--;
                }
            }

            while(left <= right) {
                result[left] = pivot;
                left++;
            }

            return result;
        }
        vector<int> pivotArray2(vector<int>& nums, int pivot) {
            int left = 0;
            int right = nums.size()-1;
            vector<int> result(nums.size(),0);
    
            for(int i = 0, j = nums.size()-1; i < nums.size(); ++i, --j) {
                if(nums[i] < pivot) {
                    result[left] = nums[i];
                    left++;
                }
                if(nums[j] > pivot) {
                    result[right] = nums[j];
                    right--;
                }
            }
    
            while(left <= right) {
                result[left] = pivot;
                left++;
            }
    
            return result;
        }

        vector<int> pivotArray3(vector<int>& nums, int pivot) {
            vector<int> less, high, result(nums.size());
            int count = 0;
    
            for(auto num : nums) {
                if(num < pivot) less.push_back(num);
                if(num == pivot) count++;
                if(num > pivot) high.push_back(num);
            }
    
            int index = 0;
            for(auto num : less) result[index++] = num;
            for(int i = 0; i < count; i++) result[index++] = pivot;
            for(auto num : high) result[index++] = num;
    
            return result;
        }
    };

int main(int argc, char* argv[]) {
    Solution* s = new Solution();
    vector<vector<vector<int>>> v ={
        {{9,12,5,10,14,3,10},{10}},
        {{-3,4,3,2},{2}}
    };

    cout << "pivotArray" << endl;
    for(auto i : v) {
        vector<int> result = s->pivotArray(i[0], i[1][0]);
        for(auto j : result) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl << "pivotArray2" << endl;

    for(auto i : v) {
        vector<int> result = s->pivotArray(i[0], i[1][0]);
        for(auto j : result) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl << "pivotArray3" << endl;

    for(auto i : v) {
        vector<int> result = s->pivotArray(i[0], i[1][0]);
        for(auto j : result) {
            cout << j << " ";
        }
        cout << endl;
    }
}