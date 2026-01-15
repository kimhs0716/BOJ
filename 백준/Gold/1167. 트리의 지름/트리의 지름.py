import sys
input = lambda: sys.stdin.readline().rstrip()
MOD = 10**9+7
INF = float('inf')

sys.setrecursionlimit(10**5+1000)


n = int(input())
adj = [[] for _ in range(n)]
for _ in range(n):
    t = list(map(int, input().split()))
    u = t[0]
    idx = 1
    while True:
        if t[idx] == -1: break
        adj[u-1].append((t[idx]-1, t[idx+1]))
        idx += 2

l = [0]*n
d = [0]*n

def dfs(cur, par):
    c0, c1 = 0, 0
    for nxt, w in adj[cur]:
        if nxt == par: continue
        dfs(nxt, cur)
        l[cur] = max(l[cur], l[nxt]+w)
        d[cur] = max(d[cur], d[nxt])
        c1 = max(c1, l[nxt]+w)
        if c0<c1: c0, c1 = c1, c0
    d[cur] = max(d[cur], c0+c1)

dfs(0, -1)

print(max(d))
