#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> leftPrefixButSelf(n);
        vector<int> rightPrefix(n);

        leftPrefixButSelf[0] = 1;
        rightPrefix[0] = nums[n-1];

        int previous = nums[0];
        for(int i = 1; i < n; i++) {
            rightPrefix[i] = rightPrefix[i-1] * nums[n-1-i];
            leftPrefixButSelf[i] = previous;
            previous *= nums[i];
        }

        for(int i = 0; i < n-1; i++) {
            answer[i] = leftPrefixButSelf[i] * rightPrefix[n - (i+2)];
        }

        answer[n-1] = leftPrefixButSelf[n-1];
        return answer;
    }
};
