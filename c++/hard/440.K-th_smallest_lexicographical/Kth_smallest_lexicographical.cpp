#include <vector>
#include <string>

class Solution {
public:
    int findKthNumber(int n, int k) {
        vector<int> nums;

        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        sort(nums.begin(), nums.end(), [](int& a, int& b){
            return to_string(a) < to_string(b);
        });

        return nums[k-1];
    }
};