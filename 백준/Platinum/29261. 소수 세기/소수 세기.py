import sys
sys.setrecursionlimit(int(1e6))

import random

def __isprime(n):
    if n < 2: return False
    if n == 2: return True
    if n % 2 == 0: return False
    i = 3
    while i * i <= n:
        if n % i == 0: return False
        i += 2
    return True

cache = {2: 1, 3: 1}

def solve(n):
    global cache
    if n in cache:
        return cache[n]
    cache[n] = 0
    for i in range(n // 2, 1, -1):
        if __isprime(i) and __isprime(n - i - 1):
            cache[n] = solve(i) + solve(n - i - 1) + 1
            break
    return cache[n]

n = int(input())
print(solve(n))
