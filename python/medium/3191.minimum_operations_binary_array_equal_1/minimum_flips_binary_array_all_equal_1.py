from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        flip_count = 0

        for i in range(len(nums)-2):
            left = nums[i]
            middle = nums[i+1]
            right = nums[i+2]

            if left == 0:
                nums[i] = int(not left)
                nums[i+1] = int(not middle)
                nums[i+2] = int(not right)
                flip_count+=1

        if nums[len(nums)-2] != 1 or nums[len(nums)-1] != 1:
            flip_count = -1

        return flip_count
