#include <vector>
#include <sort>

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sortSubArrays(n * (n+1) / 2);

        int index = 0;
        for(int i = 0; i < n; i++) {
            sortSubArrays[index++] = nums[i];
            int accomulated = nums[i];
            for(int j = i+1; j < n; j++) {
                accomulated += nums[j];
                sortSubArrays[index++] = accomulated;
            }
        }

        sort(sortSubArrays.begin(), sortSubArrays.end());

        long sum = 0;
        while(left <= right) {
            sum += sortSubArrays[left-1];
            left++;
        }

        int modulo = 1000000007;

        return sum%modulo;
    }
};