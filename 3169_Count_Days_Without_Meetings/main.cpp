#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>> meetings) {
        int today = 0;

        sort(meetings.begin(), meetings.end());

        for(auto& meeting : meetings) {
            int i = meeting[0], j = meeting[1];

            if(j <= today) continue;
            else if(i > today) days -= j - i + 1;
            else days -= j - today;

            today = j;
        }

        return days;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;

    vector<pair<int, vector<vector<int>>>> test_cases = {
        {10, {{5,7},{1,3},{9,10}}},
        {5, {{2,4},{1,3}}},
        {6, {{1,6}}}
    };

    for(auto& test_case : test_cases) {
        cout << solution.countDays(test_case.first, test_case.second) << endl;
    }

    return 0;
}