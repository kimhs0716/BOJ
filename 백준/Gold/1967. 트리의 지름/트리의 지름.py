import sys
input = lambda: sys.stdin.readline().rstrip()
MOD = 10**9+7
INF = float('inf')

sys.setrecursionlimit(10**5)


n = int(input())
adj = [[] for _ in range(n)]
for _ in range(n-1):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append((v, w))
    adj[v].append((u, w))

dist = [0] * n
def dfs(cur, par, d):
    dist[cur] = d
    for nxt, w in adj[cur]:
        if nxt == par: continue
        dfs(nxt, cur, d+w)

dfs(0, -1, 0)
M = max(dist)
for i in range(n):
    if dist[i] == M:
        break

dfs(i, -1, 0)

print(max(dist))
