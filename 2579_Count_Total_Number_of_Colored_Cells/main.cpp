#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  long long coloredCells(int n) {
    if (n == 1)
      return 1;
    long long i = n;
    long long result = (i - 1) * (i - 1) + i * i;
    return result;
  }

  long long coloredCells2(int n) {
    if (n == 1)
      return 1;
    return coloredCells(n - 1) + 4 * (n - 1);
  }
};

int main(int argc, char *arcv[]) {
  Solution solution;
  vector<int> test_cases = {1, 2, 3, 4, 5, 6};

  cout << "Solution 1" << endl;

  for (auto test_case : test_cases) {
    cout << solution.coloredCells(test_case) << endl;
  }

  cout << endl << "Solution 2" << endl;

  for (auto test_case : test_cases) {
    cout << solution.coloredCells2(test_case) << endl;
  }

  return 0;
}