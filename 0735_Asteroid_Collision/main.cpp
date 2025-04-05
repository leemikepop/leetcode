#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
        // worst case O(n^2) time complexity
        vector<int> asteroidCollision(vector<int>& asteroids) {
            int i = asteroids.size()-1;
            while(i > 0) {
                int a = asteroids[i-1];
                int b = asteroids[i];
                if(explode(a, b)) {
                    asteroids.erase(asteroids.begin() + i);
                    asteroids.erase(asteroids.begin() + i - 1);
                    if(abs(a) != abs(b)) asteroids.insert(asteroids.begin() + i - 1, abs(a) > abs(b) ? a : b);
                    i = asteroids.size()-1;
                } else {
                    i--;
                }
            }
            return asteroids;
        }

        vector<int> asteroidCollision_stack(vector<int>& asteroids) {
            stack<int> stack;
            for(int num : asteroids) {
                if(num > 0) {
                    stack.push(num);
                } else {
                    while(!stack.empty() && stack.top() > 0 && stack.top() < -num) {
                        stack.pop();
                    }
                    if(stack.empty() || stack.top() < 0) {
                        stack.push(num);
                    } else if(stack.top() == -num) {
                        stack.pop();
                    }
                }
            } 
            vector<int> result;
            while(!stack.empty()) {
                result.push_back(stack.top());
                stack.pop();
            }
            return result;
        }
    
        bool explode(int a, int b) {
            return (a > 0 && b < 0);
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> test_cases = {
        {5, 10, -5},
        {8, -8},
        {10, 2, -5},
        {-2, -1, 1, 2},
        {-2, -2, 1, -1}
    };
    cout << "Solution 1: " << endl;
    for(auto& test_case : test_cases) {
        vector<int> result = sol.asteroidCollision(test_case);
        cout << "Result: ";
        for(int i : result) cout << i << " ";
        cout << endl;
    }

    cout << endl << "Solution 2: " << endl;
    for(auto& test_case : test_cases) {
        vector<int> result = sol.asteroidCollision_stack(test_case);
        cout << "Result: ";
        for(int i : result) cout << i << " ";
        cout << endl;
    }
    return 0;
}