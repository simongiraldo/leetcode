#include <vector>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1 || k == 0) return;

        if(k % nums.size() == 0) return;

        int sizeToFront = k;
        if(k > nums.size()) {
            sizeToFront = k % nums.size();
        }

        // Get elements to be rotated
        vector<int> numsToFront(sizeToFront);
        for(int i = 0; i < numsToFront.size(); i++) {
            numsToFront[i] = nums[nums.size()-(numsToFront.size()-i)];
        }

        // Move elements to the end that does not have to rotate
        int elementsTomoveToEnd = nums.size() - numsToFront.size();
        for(int i = elementsTomoveToEnd; i > 0; i--) {
            nums[(nums.size() - 1) - (elementsTomoveToEnd - i)] = nums[i-1];
        }

        // Move element to be rotate to the front
        for(int i = 0; i < numsToFront.size(); i++) nums[i] = numsToFront[i];
    }
};