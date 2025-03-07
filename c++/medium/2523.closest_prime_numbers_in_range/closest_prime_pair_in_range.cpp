#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> allPrimes(right+1, true);

        for(int i = 2; i*i <= right; i++) {
            if(allPrimes[i]) {
                for(int j = i*i; j <= right; j+=i) {
                    allPrimes[j] = false;
                }
            }
        }

        vector<int> primes;
        for(int i = 2; i < allPrimes.size(); i++) {
            if(allPrimes[i] && i >= left) {
                primes.push_back(i);   
            }
        }

        vector<int> answer = {-1, -1};
        int minDiff = INT_MAX;
        for(int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i-1];
            if(diff < minDiff) {
                minDiff = diff;
                answer[0] = primes[i-1];
                answer[1] = primes[i];
            }
        }

        return answer;
    }
};
