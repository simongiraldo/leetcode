#include <vector>


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums[0];

        int left = 0;
        int right = 0;
        double sum = nums[0];

        while(right < k-1) {
            right++;
            sum += nums[right];
        }

        double maxAverage = sum / k;
        for(int i = right; i < nums.size(); i++) {
            int count = (right+1-left);
            if(count < k) {
                right++;
                sum += nums[right];
                count++;
            }

            if(count == k) {
                double currentAverage = sum / count;
                if(currentAverage > maxAverage) {
                    maxAverage = currentAverage;
                } 
                sum -= nums[left];
                left++;
            }

        }

        return maxAverage;
    }
};