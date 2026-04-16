import sys
sys.setrecursionlimit(10000)

cache = {(1, 1): 0}

def isprime(n):
    if n < 2: return 0
    if n == 2: return 1
    if n % 2 == 0: return 0
    i = 3
    while i * i <= n:
        if n % i == 0: return 0
        i += 2
    return 1

def f(arr):
    #print(arr)
    if arr in cache:
        return cache[arr]
    cache[arr] = 0
    cache[arr] = (f((arr[0] - 1, arr[1]))) if arr[0] > 1 else 0
    cache[arr] = max(cache[arr], (f((arr[0], arr[1] - 1))) if arr[1] > 1 else 0)
    cache[arr] += isprime(int('%d%d' % (arr[0], arr[1])))
    return cache[arr]

n = int(input())
print(f((n, n)))
