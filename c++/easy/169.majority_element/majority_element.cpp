#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numsCount;

        for(int i = 0; i < nums.size(); i++) {
            if(numsCount.find(nums[i]) == numsCount.end()) {
                numsCount[nums[i]] = 1;
            } else {
                numsCount[nums[i]]++;
            }
        }

        int target = nums.size() / 2;
        
        for(auto pair : numsCount) {
            if(pair.second > target) {
                return pair.first;
            }
        }

        return 0;
        
    }
};