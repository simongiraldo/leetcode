from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        if len(nums) == 1:
            return int(nums[0] >= target)

        if nums[0] >= target:
            return 1

        min_len = float("inf")
        left = 0
        right = 0
        window_sum = nums[0]

        while left < len(nums):
            if window_sum < target and right + 1 == len(nums):
                break

            if window_sum < target:
                right += 1
                window_sum += nums[right]
                continue

            current_len = right + 1 - left
            if current_len < min_len:
                min_len = current_len
                if min_len == 1:
                    return 1

            window_sum -= nums[left]
            left += 1

        return min_len if min_len != float("inf") else 0
