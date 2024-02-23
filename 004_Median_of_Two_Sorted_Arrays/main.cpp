#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n2 < n1)
            return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;
        int leftPartitionSize = (n + 1) >> 1; // 6
        int l = 0, r = n1;
        /*  (index)   l        r
            num1 = - [1 2 3 4] +
            num2 = - [1 2 3 4 5 6 7 8] +
        */
        while (l <= r) {
            int m1 = (l + r + 1) >> 1;       // length of left partition in num1
            int m2 = leftPartitionSize - m1; // length of left partition in num2
            /*              l1  r1
                num1 = - [1 2 | 3 4] +           m1 = 2
                                l2  r2
                num2 = - [1 2 3 4 | 5 6 7 8] +   m2 = 4 (6-2)
            */
            /*         l1   r1
                num1 = - [] +            m1 = n1= 0
                         l1  r1
                num1 = - [1] +           m1 = 1
            */
            int l1 = m1 >= 1 ? nums1[m1 - 1] : INT_MIN;
            int r1 = m1 < n1 ? nums1[m1] : INT_MAX;
            int l2 = m2 >= 1 ? nums2[m2 - 1] : INT_MIN;
            int r2 = m2 < n2 ? nums2[m2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) {
                    return l1 >= l2 ? l1 : l2;
                } else {
                    return ((double)(std::max(l1, l2) + std::min(r1, r2))) / 2.0;
                }
            } else if (l1 > r2) {
                r = m1 - 1;
            } else {
                l = m1;
            }
        }
        return 0;
    }
};


int main(int argc, char* argv[]){
    Solution *s = new Solution();
    //ex1
    std::vector<int> v1 = {1, 3};
    std::vector<int> v2 = {2};

    double ret = s->findMedianSortedArrays(v1, v2);
    std::cout << ret << std::endl;

    //ex2
    std::vector<int> v3 = {1, 2};
    std::vector<int> v4 = {3, 4};

    double ret1 = s->findMedianSortedArrays(v3, v4);
    std::cout << ret1 << std::endl;

    return 0;
}