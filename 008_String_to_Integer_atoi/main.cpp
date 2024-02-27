#include <iostream>
#include <vector>
#include <string>

using std::string;

class Solution {
public:
    int myAtoi(string s) {
        string digits = "0123456789";
        int num_begin, num_end;
        int state = 0; //0:還沒找到合法數字 1:找到合法數字
        for(size_t idx = 0; idx < s.size(); idx++){
            char c = s[idx];

            /*開頭空格合法直接忽略*/
            if(state==0 && c==' ')continue;
            /*+-符號開頭且後面接著數字*/
            if(state==0 && (c=='+' || c=='-') && (idx+1 < s.size()) && isdigit(s[idx+1], digits)){
                num_begin = idx;
                state = 1; //find begin
                continue;
            }
            /*非空格且非+-或數字開頭，直接回傳0*/
            if(state==0 && !isdigit(c, digits))break;
            /*找到合法數字，改state=1*/
            if(state==0 && isdigit(c, digits)){
                num_begin = idx;
                state = 1; //find begin
                continue;
            }
            /*找到合法數字開頭但遇到非數字結尾，結束*/
            if(state==1 && !isdigit(c, digits)){
                num_end = idx;
                break;
            }
            /*找到合法數字開頭，此char可能是合法結尾*/
            num_end = idx + 1;
        }
        if(state==0){
            return 0;
        }else{
            string ret = s.substr(num_begin,num_end);
            try{
                return stoi(ret);
            } catch (const std::out_of_range& e) {
                /*超過range [-2^31, 2^31 - 1]時採用飽和運算*/
                if(ret[0]=='-'){
                    return -2147483648; //-2^31
                }else{
                    return 2147483647; //2^31-1
                }
            }            
        }
    }

    bool isdigit(char c, string digits){
        //digits = "0123456789"
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