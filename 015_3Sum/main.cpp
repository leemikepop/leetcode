#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
#include <iomanip>

using namespace std;

/*overload ostream << to print a vector of vectors*/
template <typename T> struct is_container {
    static constexpr bool value = false;
};
template <typename T, typename Allocator>
struct is_container<vector<T, Allocator>> {
    static constexpr bool value = true;
};
template <typename T>
typename enable_if<is_container<T>::value, ostream &>::type
inline operator<<(ostream &os, const T &container) {
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

// Overload the << operator to print unordered_map<int, int>
ostream& operator<<(ostream& os, const unordered_map<int, int>& hashmap) {
    os << "{";
    for_each(hashmap.begin(), hashmap.end(), [&os](const pair<int, int>& p) {
        os << "[" << p.first << ", " << p.second << "], ";
    });
    os << "\b\b}";
    return os;
}
// Overload the << operator to print unordered_map<int, int>
// ostream& operator<<(ostream& os, const unordered_map<int, int>& hashmap) {
//     os << "{";
//     for (const auto& [key, value] : hashmap) {
//         os << "[" << key << ", " << value << "], ";
//     }
//     os << "\b\b}";
//     return os;
// }

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // Hint 2 : Sort
        cout << setw(11) << setfill(' ') << "Original: " << nums << endl;
        sort(nums.begin(), nums.end());
        cout << setw(11) << setfill(' ') << "Sorted: " << nums << endl;
        if (nums[0] > 0) {
            return {};
        }
        // Hint 3 : hashMap
        unordered_map<int, int> hashMap; // num : index
        for (int i = 0; i < nums.size(); i++) {
            hashMap[nums[i]] = i;
        }

        cout << setw(11) << setfill(' ') << "hashMap: " << hashMap << endl;

        vector<vector<int>> ret;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0)
                break;
            for (int j = i + 1; j < nums.size() - 1; j++) {
                int target = ~(nums[i] + nums[j]) + 1; // multiply -1
                // if(hashMap.find(target)!=hashMap.end() && hashMap[target] >
                // j)
                if (hashMap.count(target) && hashMap.find(target)->second > j) {
                    ret.push_back({nums[i], nums[j], target});
                }
                j = hashMap.find(nums[j])->second;
            }
            i = hashMap.find(nums[i])->second;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution *sol = new Solution();
    vector<vector<int>> test_cases = {
        {-1, 0, 1, 2, -1, -4}, {-1, 0, 1, 2, -1, -4, 0}, {0, 1, 1}, {0, 0, 0}};

    for (vector<int> test_case : test_cases) {
        vector<vector<int>> ret = sol->threeSum(test_case);
        cout << setw(11) << setfill(' ') << "Result: " << ret << endl << endl;
    }
    return 0;
}