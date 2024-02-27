#include <iostream>
#include <vector>
#include <string>

using std::string;

class Solution {
public:
    int myAtoi(string s) {
        string digits = "0123456789";
        int num_begin, num_end;
        int state = 0;
        for(size_t idx = 0; idx < s.size(); idx++){
            char c = s[idx];
            if(state==0 && c==' ')continue;            
            if(state==0 && (c=='+' || c=='-') && (idx+1 < s.size()) && isdigit(s[idx+1], digits)){
                num_begin = idx;
                state = 1; //find begin
                continue;
            }
            if(state==0 && !isdigit(c, digits))break;
            if(state==0 && isdigit(c, digits)){
                num_begin = idx;
                state = 1; //find begin
                continue;
            }
            if(state==1 && !isdigit(c, digits)){
                num_end = idx;
                break;
            }
            num_end = idx + 1;
        }
        if(state==0){
            return 0;
        }else{
            string ret = s.substr(num_begin,num_end);
            try{
                return stoi(ret);
            } catch (const std::out_of_range& e) {
                if(ret[0]=='-'){
                    return -2147483648;
                }else{
                    return 2147483647;
                }
            }            
        }
    }

    bool isdigit(char c, string digits){
        if(digits.find(c)==string::npos){
            return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]){
    Solution *sol = new Solution();
    std::vector<string> test_cases = {
        "42",
        "   -42",
        "4193 with words",
        "words and 987",
        "-91283472332",
        "91283472332"
    };

    for(string test_case : test_cases){
        std::cout << sol->myAtoi(test_case) << std::endl;
    }
    return 0;
}