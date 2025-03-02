class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        if(nums.size() == 0) {
            return;
        }

        vector<int> prefixSum(nums.size());
        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        this->nums = prefixSum;
    }
    
    int sumRange(int left, int right) {
        if(left == 0) {
            return this->nums[right];
        }

        return this->nums[right] - this->nums[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */