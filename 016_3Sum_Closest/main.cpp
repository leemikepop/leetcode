/*
https://leetcode.com/problems/3sum-closest/description/
*/
#include <algorithm>
#include <climits>
#include <ctime>
#include <iostream>
#include <utility> //pair
#include <vector>

using std::pair;
using std::string;
using std::vector;

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ret = 1234567, diff = INT_MAX;

        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int three_sum = nums[i] + nums[l] + nums[r];
                if (three_sum == target) {
                    return three_sum;
                } else if (three_sum > target) {
                    r--;
                } else { // three_sum < target
                    l++;
                }
                if (abs(three_sum - target) < diff) {
                    diff = abs(three_sum - target);
                    ret = three_sum;
                }
            }
        }
        return ret;
    }
    int abs(int x) {
        int mask = x >> 31;
        return (x + mask) ^ mask;
    }
};

int main(int argc, char* argv[]){
    clock_t start = clock();

    Solution *sol = new Solution();
    vector<pair<vector<int>, int>> test_cases = {
        {{-1, 2, 1, -4}, 1},
        {{0, 0, 0}, 1},
        {{833,  736,  953,  -584, -448, 207,  128,  -445, 126,  248,  871,
          860,  333,  -899, 463,  488,  -50,  -331, 903,  575,  265,  162,
          -733, 648,  678,  549,  579,  -172, -897, 562,  -503, -508, 858,
          259,  -347, -162, -505, -694, 300,  -40,  -147, 383,  -221, -28,
          -699, 36,   -229, 960,  317,  -585, 879,  406,  2,    409,  -393,
          -934, 67,   71,   -312, 787,  161,  514,  865,  60,   555,  843,
          -725, -966, -352, 862,  821,  803,  -835, -635, 476,  -704, -78,
          393,  212,  767,  -833, 543,  923,  -993, 274,  -839, 389,  447,
          741,  999,  -87,  599,  -349, -515, -553, -14,  -421, -294, -204,
          -713, 497,  168,  337,  -345, -948, 145,  625,  901,  34,   -306,
          -546, -536, 332,  -467, -729, 229,  -170, -915, 407,  450,  159,
          -385, 163,  -420, 58,   869,  308,  -494, 367,  -33,  205,  -823,
          -869, 478,  -238, -375, 352,  113,  -741, -970, -990, 802,  -173,
          -977, 464,  -801, -408, -77,  694,  -58,  -796, -599, -918, 643,
          -651, -555, 864,  -274, 534,  211,  -910, 815,  -102, 24,   -461,
          -146}, -7111}
    };

    for (pair<vector<int>, int> test_case : test_cases) {
        std::cout << sol->threeSumClosest(test_case.first, test_case.second)
                  << std::endl;
    }

    clock_t end = clock();
    double duration = (double)(end - start) / (__clock_t)1000;
    std::cout << std::endl << "Exicution Time: " << duration << " ms" << std::endl;
    return 0;
}