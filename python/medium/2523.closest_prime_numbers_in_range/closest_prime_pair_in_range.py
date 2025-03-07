# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
from typing import List;

# left <= num1 < num2 <= right
# num1 & num2 are prime numbers
# num2 - num1 = minimum pair that meets conditions
# if there are multiple pairs return the one with smallest num1

def closestPrimes(left: int, right: int) -> List[int]:
    all_primes = sieve_erathostenes(left, right)
    primes = []
    for i in all_primes:
        if i >= left:
            primes.append(i)
            
    answer = [-1, -1]
    min_diff = float('inf')
    for i in range(1, len(primes)):
        diff = primes[i] - primes[i-1]
        if diff < min_diff or (diff == min_diff and primes[i-1] < answer[0]):
            min_diff = diff
            answer[0] = primes[i-1]
            answer[1] = primes[i]
        
    return answer
    
        
def sieve_erathostenes(left, n):
    primes = [True] * (n+1)
    i = 2
    while i*i <= n:
        if primes[i]:
            for j in range(i*i, n+1, i):
                primes[j] = False
        
        i +=1
        
    real_primes = []
    for i in range(2, len(primes)):
        if primes[i] and i >= left:
            real_primes.append(i)
            
    return real_primes
        
        
# 29, 31
left = 19
right = 31
result = closestPrimes(left, right)
print(result)
print("\n\n")
n = 31
print(sieve_erathostenes(0, n))
            