import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
adj = [[] for _ in range(n)]
par = [[-1] * 17 for _ in range(n)]
depth = [0] * n

for _ in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    adj[a].append(b)
    adj[b].append(a)

par[0][0] = 0
st = [(0, -1)]
while st:
    c, p = st.pop()
    for n in adj[c]:
        if n==p: continue
        par[n][0] = c
        depth[n] = depth[c] + 1
        st.append((n, c))

n = len(adj)
for i in range(1, 17): # find 2^i-th parent
    for j in range(n):
        par[j][i] = par[par[j][i-1]][i-1]

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
            v = par[v][i]
        diff >>= 1
    for i in range(16, -1, -1):
        pu = par[u][i]
        pv = par[v][i]
        if pu != pv:
            u = pu
            v = pv
    if u==v: print(u+1)
    else: print(par[u][0]+1)


