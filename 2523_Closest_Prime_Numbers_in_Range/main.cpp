#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
    private:
        bool isPrime(int num) {
            if (num <= 1) return false;
            for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0)
                    return false;
            }
            return true;
        }

        vector<int> sieve(int left, int right) {
            vector<bool> isPrime(right+1, true);
            isPrime[0] = isPrime[1] = false;
            for(int i = 2; i * i <= right; i++) {
                if(isPrime[i]) {
                    for(int j = i*i; j <= right; j+=i) {
                        isPrime[j] = false;
                    }
                }
            }

            vector<int> prime;
            for(int i = left; i <= right; i++) {
                if(isPrime[i]) prime.push_back(i);
            }

            return prime;
        }        
      
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<int> ans;
            vector<int> prime;
            while(left <= right) {
                bool test = true;
                test = isPrime(left);
                if(test == true) prime.push_back(left);
                left++;
            }
            if(prime.size() <= 1) {
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
            vector<pair<int, vector<int>>> dis;
            for(int i = 0; i < prime.size()-1; i++) {
               dis.push_back({prime[i+1]-prime[i], {prime[i], prime[i+1]}});
            }
            sort(dis.begin(), dis.end());
            ans.push_back(dis[0].second[0]);
            ans.push_back(dis[0].second[1]);
            return ans;
        }

        vector<int> closestPrimesFaster(int left, int right) {
            vector<int> ans;
            vector<int> prime = sieve(left,right);

            if(prime.size() <= 1) {
                ans = {-1,-1};
                return ans;
            }
            vector<pair<int, vector<int>>> dis;
            int min = prime[1]-prime[0];
            ans = {prime[0], prime[1]};
            for(int i = 1; i < prime.size()-1; i++) {
                int res = prime[i+1]-prime[i];
                if(min > res) {
                    min = res;
                    ans = {prime[i], prime[i+1]};
                }
            }
            return ans;
        }
    };

int main() {
    Solution* sol = new Solution();
    vector<vector<int>> test_cases = {
        {10,19},
        {4,6},
        {19,31},
        {12854,130337}
    };

    cout << "Brute Force :" << endl;

    for(auto test_case : test_cases) {
        vector<int> ans = sol->closestPrimes(test_case[0], test_case[1]);
        for(auto a : ans) {
            cout << a << " ";
        }
        cout << endl;
    }

    cout << endl << "Sieve :" << endl;

    for(auto test_case : test_cases) {
        vector<int> ans = sol->closestPrimesFaster(test_case[0], test_case[1]);
        for(auto a : ans) {
            cout << a << " ";
        }
        cout << endl;
    }
}