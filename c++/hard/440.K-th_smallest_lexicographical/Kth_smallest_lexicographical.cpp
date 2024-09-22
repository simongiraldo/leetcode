#include <vector>
#include <string>

class Solution {
public:
    int findKthNumber(int n, int k) {
        vector<string> nums;

        for(int i = 1; i <= n; i++) {
            nums.push_back(to_string(i));
        }

        sort(nums.begin(), nums.end());

        return stoi(nums[k-1]);
    }
};