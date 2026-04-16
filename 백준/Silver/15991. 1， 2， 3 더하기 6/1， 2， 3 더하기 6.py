mod = int(1e9+9)

cache = {}
cache[1] = 1
cache[2] = 2
cache[3] = 2
cache[4] = 3
cache[5] = 3
cache[6] = 6

for i in range(7, 100001):
    cache[i] = cache[i - 2]
    cache[i] += cache[i - 4]
    cache[i] += cache[i - 6]
    cache[i] %= mod

t = int(input())
for i in range(t):
    n = int(input())
    print(cache[n])
