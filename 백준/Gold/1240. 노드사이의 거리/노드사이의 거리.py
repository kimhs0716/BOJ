import sys
input = lambda: sys.stdin.readline().rstrip()


def dfs(cur, par, d):
    dist[cur] = d
    for nxt, w in adj[cur]:
        if nxt == par: continue
        dfs(nxt, cur, d+w)



n, m = map(int, input().split())
adj = [[] for _ in range(n)]

for _ in range(n-1):
    u, v, w = map(int, input().split())
    adj[u-1].append((v-1, w))
    adj[v-1].append((u-1, w))

dist = [-1] * n
for _ in range(m):
    u, v = map(int, input().split())
    dfs(u-1, -1, 0)
    print(dist[v-1])
