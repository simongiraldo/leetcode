from typing import List

class Solution:
    mod = 10**9 + 7

    def numOfSubarrays(self, arr: List[int]) -> int:
        if len(arr) == 1:
            return int(arr[0] % 2 != 0)

        total = 0
        prefixSum = 0
        odd = 0
        even = 1

        for i in arr:
            prefixSum += i
            if prefixSum % 2 != 0:
                total += even
                odd += 1
            else:
                total += odd
                even += 1
            
                
        return total % self.mod
        