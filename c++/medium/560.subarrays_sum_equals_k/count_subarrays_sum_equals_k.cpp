#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1) {
            return nums[0] == k;
        }

        vector<int> prefixSum;
        prefixSum.reserve(nums.size());
        prefixSum.push_back(nums[0]);

        unordered_map<int, int> sumCounter;
        sumCounter[0] = 1;
        sumCounter[nums[0]] += 1;
        
        int total = 0;
        if(nums[0] == k) total++;

        for(int i = 1; i < nums.size(); i++) {
            int current = prefixSum[i-1] + nums[i];

            if(sumCounter.find(current - k) != sumCounter.end()) {
                total += sumCounter[current - k];
            }

            prefixSum.push_back(current);
            sumCounter[current]++;
        }
        
        return total;
    }
};
