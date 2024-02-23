#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      if (numMap.find(complement) != numMap.end()) {
        return {numMap[complement], i};
      }
      numMap[nums[i]] = i;
    }
    return {};
  }
};

int main() {
  vector<int> nums1 = {2, 7, 11, 15};
  vector<int> ret = (new Solution())->twoSum(nums1, 9);

  for (int &num : ret) {
    cout << num << "\t";
  }
  cout << endl;
}