#include <vector>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int indexNotVal = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[indexNotVal++] = nums[i];
            } else {
                nums[i] = 0;
            }
        }

        return indexNotVal;   
    }
};