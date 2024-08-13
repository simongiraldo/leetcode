#include <vector>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return true;

        int index = 0;
        while(index < nums.size()-1) {
            if(nums[index] == 0) {
                int j = index-1;
                int toJump = 2;
                bool canJump = false;
                while(j >= 0) {
                    if(nums[j] >= toJump) {
                        canJump = true;
                        break;
                    }

                    j--;
                    toJump++;
                }

                if(!canJump) return false;
            }

            index++;
        }

        return true;
    }
};