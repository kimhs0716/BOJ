import sys
input = lambda: sys.stdin.readline().rstrip()
MOD = 10**9+7
INF = float('inf')

sys.setrecursionlimit(10**5+1000)


def bf(edges, n, src):
    dist = [INF] * n
    dist[src] = 0
    for i in range(n):
        for u, v, w in edges:
            if dist[u] != INF and dist[v]>dist[u]+w:
                dist[v] = dist[u]+w
                if i==n-1: return True, dist
    return False, dist


k, n = map(int, input().split())
edges = []
adj = [[] for _ in range(k+2)]
for i in range(k):
    edges.append((i+1, i, 0))
    edges.append((i, i+1, 1))
for i in range(k+1):
    edges.append((k+1, i, 0))

for _ in range(n):
    u, v, w = map(int, input().split())
    edges.append((v, u-1, -w))
    edges.append((u-1, v, w))

neg_cycle, dist = bf(edges, k+2, k+1)

if neg_cycle: print("NONE")
else:
    d = dist[0]
    for i in range(k+1):
        dist[i] -= d
    res = []
    for i in range(k):
        res.append('-#'[dist[i+1]-dist[i]])
    print(''.join(res))

