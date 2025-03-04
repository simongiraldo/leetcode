from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        if len(nums) == 1:
            return int(nums[0] >= target)

        min_len = 1 if nums[0] >= target else float('inf')
        prefix_index = {0:0}
        prefix_index[nums[0]] = 0
        prefix_sum = [0] * len(nums)
        prefix_sum[0] = nums[0]

        for i in range(1, len(nums)):
            current = prefix_sum[i-1] + nums[i]
            if current >= target:
                index = 0
                if current - target in prefix_index:
                    index = prefix_index[current - target]
                    current_len = i - index
                else:
                    diff = current - target
                    if diff - (nums[i] - diff) in prefix_index:
                        index = prefix_index[diff - (nums[i] - diff)]

                    current_len = i - index
                
                if current_len < min_len:
                    min_len = current_len


            prefix_sum[i] = current
            prefix_index[current] = i 

        return min_len if min_len != float('inf') else 0

