#include <algorithm>
#include <ctime>
#include <iostream>
#include <utility> //pair
#include <vector>

using std::pair;
using std::string;
using std::vector;

/*overload ostream << to print a vector of vectors*/
template <typename T> struct is_container {
    static constexpr bool value = false;
};
template <typename T, typename Allocator>
struct is_container<vector<T, Allocator>> {
    static constexpr bool value = true;
};
template <typename T>
typename std::enable_if<is_container<T>::value, std::ostream &>::type inline
operator<<(std::ostream &os, const T &container) {
    const auto N = container.size();
    size_t current = 0;
    os << "[";
    for (const auto &item : container) {
        const char *separator = current++ == N - 1 ? "" : ", ";
        os << item << separator;
    }
    os << "]";
    return os;
}

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ret = {};
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    long long sum = 0;
                    sum += nums[i];
                    sum += nums[j];
                    sum += nums[l];
                    sum += nums[r];
                    if (sum == target) {
                        ret.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l - 1] == nums[l])
                            l++;
                        while (l < r && nums[r + 1] == nums[r])
                            r--;
                    } else if (sum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    clock_t start = clock();

    Solution *sol = new Solution();
    vector<pair<vector<int>, int>> test_cases = {
        {{1, 0, -1, 0, -2, 2}, 0},
        {{2, 2, 2, 2, 2}, 8},
        {{1000000000, 1000000000, 1000000000, 1000000000}, 0}};

    for (pair<vector<int>, int> test_case : test_cases) {
        std::cout << sol->fourSum(test_case.first, test_case.second)
                  << std::endl;
    }

    clock_t end = clock();
    double duration = (double)(end - start) / (__clock_t)1000;
    std::cout << std::endl
              << "Exicution Time: " << duration << " ms" << std::endl;
    return 0;
}