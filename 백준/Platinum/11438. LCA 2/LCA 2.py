import sys
input = lambda: sys.stdin.readline().rstrip()


sys.setrecursionlimit(2*10**5)


n = int(input())
adj = [[] for _ in range(n)]
par = [[-1] * n for _ in range(17)]
depth = [0] * n

for _ in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    adj[a].append(b)
    adj[b].append(a)

def dfs(c, p):
    for n in adj[c]:
        if n==p: continue
        par[0][n] = c
        depth[n] = depth[c] + 1
        dfs(n, c)

par[0][0] = 0
dfs(0, -1)

for i in range(1, 17): # find 2^i-th parent
    for j in range(n):
        par[i][j] = par[i-1][par[i-1][j]]

q = int(input())
for _ in range(q):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    if depth[u] > depth[v]:
        u, v = v, u
    diff = depth[v] - depth[u]
    for i in range(17):
        if diff&1:
            v = par[i][v]
        diff >>= 1
    for i in range(16, -1, -1):
        pu = par[i][u]
        pv = par[i][v]
        if pu != pv:
            u = pu
            v = pv
    if u==v: print(u+1)
    else: print(par[0][u]+1)


