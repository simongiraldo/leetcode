#include <vector>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int notValCount = 0;
        int indexNotVal = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                notValCount++;
                nums[indexNotVal++] = nums[i];
            } else {
                nums[i] = 0;
            }
        }

        return notValCount;   
    }
};