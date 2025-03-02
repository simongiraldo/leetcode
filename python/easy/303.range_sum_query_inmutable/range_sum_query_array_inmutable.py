from typing import List

class NumArray:
    nums = []

    def __init__(self, nums: List[int]):
        if len(nums) == 0:
            return

        prefixSum = []
        prefixSum.append(nums[0])
        for i in range(1, len(nums)):
            prefixSum.append(prefixSum[i-1] + nums[i])

        self.nums = prefixSum
        

    def sumRange(self, left: int, right: int) -> int:
        if left == 0:
            return self.nums[right]

        return self.nums[right] - self.nums[left-1]
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)