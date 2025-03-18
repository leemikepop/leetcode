#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string reverseVowels(string s) {
    string reverse = "";
    string result = "";
    int j = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
          s[i] == 'O' || s[i] == 'U') {
        reverse += s[i];
      }
    }
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
          s[i] == 'O' || s[i] == 'U') {
        result += reverse[j];
        j++;
      } else {
        result += s[i];
      }
    }
    return result;
  }
  string reverseVowels_fast(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      while (left < right && !isVowel(s[left]))
        left++;
      while (left < right && !isVowel(s[right]))
        right--;

      swap(s[left], s[right]);
      left++;
      right--;
    }
    return s;
  }

private:
  bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
        c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  vector<string> test_cases = {"IceCreAm", "leetcode", " "};

  cout << "First Solution:" << endl;
  for (auto test_case : test_cases) {
    cout << sol.reverseVowels(test_case) << endl;
  }

  cout << "Second Solution:" << endl;
  for (auto test_case : test_cases) {
    cout << sol.reverseVowels_fast(test_case) << endl;
  }
}