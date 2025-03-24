#include <iostream>
#include <vector>
#include <algorithm>

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

    int countDays_merge_intervals(int days, vector<vector<int>> meetings) {
        vector<vector<int>> merged;
        sort(meetings.begin(), meetings.end());

        merged.push_back(meetings[0]);
        for(int i = 1; i < meetings.size(); i++) {
     
            vector<int>& last = merged.back();

            if(last[1] >= meetings[i][0]) {
                last[1] = max(last[1], meetings[i][1]);
            } else {
                merged.push_back(meetings[i]);
            }
        }

        for(auto& merge : merged) {
            days -= merge[1]-merge[0]+1;
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

    cout << "Solution 1:" << endl;
    for(auto& test_case : test_cases) {
        cout << solution.countDays(test_case.first, test_case.second) << endl;
    }

    cout << endl << "Solution 2 (Merging Intervals):" << endl;
    for(auto& test_case : test_cases) {
        cout << solution.countDays_merge_intervals(test_case.first, test_case.second) << endl;
    }

    return 0;
}