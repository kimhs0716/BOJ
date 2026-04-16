import sys
input = lambda: sys.stdin.readline()[:-1]

sys.setrecursionlimit(5100)
n, m = map(int, input().split())
height = [0] + [*map(int, input().split())]
graph = [set() for _ in range(n + 1)]
cache = [-1] * (n + 1)

for i in range(m):
    a, b = map(int, input().split())
    graph[a].add(b)
    graph[b].add(a)

def solution(i):
    global cache
    if cache[i] != -1: return cache[i]
    cache[i] = 0
    for j in graph[i]:
        if height[j] > height[i]:
            cache[i] = max(cache[i], solution(j))
    cache[i] += 1
    return cache[i]

for i in range(1, n + 1):
    print(solution(i))
