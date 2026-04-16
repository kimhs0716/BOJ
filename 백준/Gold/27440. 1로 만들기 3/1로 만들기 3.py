cache = {1: 0}
def solve(n):
    if n in cache: return cache[n]
    cache[n] = float('inf')
    if n % 6: cache[n] = cache[n] = min(cache[n], solve(n - 1))
    if n % 3 == 0: cache[n] = min(cache[n], solve(n // 3))
    if n % 2 == 0: cache[n] = min(cache[n], solve(n // 2))
    cache[n] += 1
    return cache[n]

print(solve(int(input())))
