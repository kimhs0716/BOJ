import sys
sys.setrecursionlimit(10 ** 6)
input = lambda: sys.stdin.readline()[:-1]

for _ in range(int(input())):
    n, k = map(int, input().split())
    parents = [[] for _ in range(n + 1)]
    times = [0] + [*map(int, input().split())]
    for _ in range(k):
        p, c = map(int, input().split())
        parents[c].append(p)
    w = int(input())

    cache = {}
    def solve(n):
        global cache
        if n in cache: return cache[n]
        cache[n] = 0
        for p in parents[n]:
            cache[n] = max(cache[n], solve(p))
        cache[n] += times[n]
        return cache[n]
    print(solve(w))
