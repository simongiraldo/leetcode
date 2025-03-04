from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if len(nums) == 1:
            return int(nums[0] == k)

        total = 1 if nums[0] == k else 0
        sumCounter = {
            0: 1,
        }
        sumCounter[nums[0]] = sumCounter.get(nums[0], 0) + 1 # in case k and first element = 0
        prefixSum = []
        prefixSum.append(nums[0])

        for i in range(1, len(nums)):
            current = prefixSum[i-1] + nums[i]
            prefixSum.append(current)
            if current-k in sumCounter:
                total += sumCounter[current-k]

            sumCounter[current] = sumCounter.get(current, 0) + 1

        return total
        