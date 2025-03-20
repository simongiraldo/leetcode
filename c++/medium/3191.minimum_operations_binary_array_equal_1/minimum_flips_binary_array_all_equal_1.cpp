#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flipCount = 0;
        int onesCount = 0;

        for(int i = 0; i < nums.size()-2; i++) {
            int left = nums[i];
            int middle = nums[i+1];
            int right = nums[i+2];

            onesCount++;

            if(left == 1) {
                continue;
            }

            nums[i] = left^1;
            nums[i+1] = middle^1;
            nums[i+2] = right^1;
            flipCount++;
        }

        onesCount += nums[nums.size()-2];
        onesCount += nums[nums.size()-1];

        return onesCount == nums.size() ? flipCount : -1;
    }
};