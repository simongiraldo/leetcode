#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 1) return nums[0] >= target;

        if(nums[0] >= target) return 1;

        int minLen = INT_MAX;
        int left = 0;
        int right = 0;
        int windowSum = nums[0];

        while(left < nums.size()) {
            if (windowSum < target && right+1 == nums.size()) break;

            if(windowSum < target) {
                right++;
                windowSum += nums[right];
                continue;
            }

            int currentLen = right+1 - left;
            if(currentLen < minLen) {
                minLen = currentLen;
                if(minLen == 1) return minLen;
            }

            windowSum -= nums[left];
            left++;
        }

        return minLen < INT_MAX ? minLen : 0;
    }
};
