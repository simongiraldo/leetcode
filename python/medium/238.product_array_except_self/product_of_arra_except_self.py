from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        answer = [0] * n

        left_prefix = [0] * n
        right_prefix = [0] * n

        left_prefix[0] = 1
        right_prefix[0] = nums[n-1]

        multiplication = nums[0]

        for i in range(1, n):
            right_prefix[i] = right_prefix[i-1] * nums[n-1-i]
            left_prefix[i] = multiplication
            multiplication *= nums[i]
        
        for i in range(0, n-1):
            answer[i] = left_prefix[i] * right_prefix[n - (i+2)]

        answer[n-1] = left_prefix[n-1]
        return answer
