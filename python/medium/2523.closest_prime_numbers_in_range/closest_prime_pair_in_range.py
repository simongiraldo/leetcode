from typing import List

class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        all_primes = [True] * (right+1)
        i = 2
        while i*i <= right:
            if all_primes[i]:
                for j in range(i*i, right+1, i):
                    all_primes[j] = False
            i+=1
        
        primes = []
        for i in range(2, len(all_primes)):
            if all_primes[i] and i >= left:
                primes.append(i)
            
        answer = [-1, -1]
        min_diff = float('inf')
        for i in range(1, len(primes)):
            diff = primes[i] - primes[i-1]
            if diff < min_diff:
                min_diff = diff
                answer[0] = primes[i-1]
                answer[1] = primes[i]
        
        return answer
