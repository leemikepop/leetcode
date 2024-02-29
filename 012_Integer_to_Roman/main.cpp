#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> roman_numerals = {
            {1, 'I'},   {5, 'V'},   {10, 'X'},  {50, 'L'},
            {100, 'C'}, {500, 'D'}, {1000, 'M'}};

        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        string ret = "";
        for (int i = digits.size() - 1; i >= 0; i--) {
            switch (digits[i]) {
            case 1:
                ret += roman_numerals[powX(i)];
                break;
            case 2:
                ret += roman_numerals[powX(i)];
                ret += roman_numerals[powX(i)];
                break;
            case 3:
                ret += roman_numerals[powX(i)];
                ret += roman_numerals[powX(i)];
                ret += roman_numerals[powX(i)];
                break;
            case 4:
                ret += roman_numerals[powX(i)];
                ret += roman_numerals[5 * powX(i)];
                break;
            case 5:
                ret += roman_numerals[5 * powX(i)];
                break;
            case 6:
                ret += roman_numerals[5 * powX(i)];
                ret += roman_numerals[powX(i)];
                break;
            case 7:
                ret += roman_numerals[5 * powX(i)];
                ret += roman_numerals[powX(i)];
                ret += roman_numerals[powX(i)];
                break;
            case 8:
                ret += roman_numerals[5 * powX(i)];
                ret += roman_numerals[powX(i)];
                ret += roman_numerals[powX(i)];
                ret += roman_numerals[powX(i)];
                break;
            case 9:
                ret += roman_numerals[powX(i)];
                ret += roman_numerals[powX(i + 1)];
                break;
            default:
                break;
            }
        }
        return ret;
    }

    int powX(int k) {
        int ans = 1;
        for (int i = 0; i < k; i++) {
            ans *= 10;
        }
        return ans;
    }
};

class Solution2 {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};

int main(int argc, char* argv[]){
    Solution *sol = new Solution();
    vector<int> test_cases = {
        3,
        58,
        1994,
        3999
    };

    for(int test_case : test_cases){
        std::cout << sol->intToRoman(test_case) << std::endl;
    }
    return 0;
}