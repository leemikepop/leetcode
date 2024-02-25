#include <iostream>
#include <utility>
#include <vector>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(numRows==1)return s;
        int n = s.size();
        std::vector<char> ret;
        ret.reserve(n);
        int step = 2*(numRows-1);
        int step1,step2;
        
        for(int i = 0; i < numRows; i++){
            int idx = i;
            if(idx >= n)break;
            ret.push_back(s[idx]);
            step2 = i*2;
            step1 = step - step2;
            
            for(int j = 0; idx < n; j++){
                if(j % 2 == 0){
                    idx += step1;
                    if(step1 == 0 || idx >= n)continue;
                    ret.push_back(s[idx]);
                }else{
                    idx += step2;
                    if(step2 == 0 || idx >= n)continue;
                    ret.push_back(s[idx]);
                }
            }
        }
        std::string res(ret.begin(), ret.end());
        return res;
    }
};

int main(int argc, char* argv[]){
    Solution *sol = new Solution();
    std::vector<std::pair<std::string,int>> test_cases = {
        std::make_pair("A", 2),
        std::make_pair("PAYPALISHIRING", 3),
        std::make_pair("PAYPALISHIRING", 4),
        std::make_pair("A", 1),
        std::make_pair("AB", 1),        
    };
    
    for(std::pair<std::string,int> test_case : test_cases){
        std::string ret = sol->convert(test_case.first, test_case.second);
        std::cout << ret << std::endl;
    }

    return 0;
}