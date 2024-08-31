import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass



class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [[0] * n for _ in range(n)]

    def add_edge(self, u, v):
        self.adj[u][v] = 1
        self.adj[v][u] = 1

def dfs(g, node=0):
    visited = set()
    stack = [node]
    ret = []
    visited.add(node)
    while stack:
        node = stack.pop()
        ret.append(node)
        for nxt, ok in enumerate(g.adj[node]):
            if not ok: continue
            if nxt in visited: continue
            stack.append(nxt)
            visited.add(nxt)
    return ret


n, k, t = map(int, input().split())
k **= 2
xx, yy, vv = map(int, input().split())
graph = Graph(n + 1)
f = []
for i in range(1, n + 1):
    x, y, v, p = map(int, input().split())
    if k >= (xx - x) ** 2 + (yy - y) ** 2 and abs(vv - v) <= t:
        graph.add_edge(0, i)
    for j in range(i - 1):
        if k >= (x - f[j][0]) ** 2 + (y - f[j][1]) ** 2 and abs(v - f[j][2]) <= t:
            graph.add_edge(j + 1, i)
    f.append((x, y, v, p))

d = sorted(dfs(graph))
ans = []

for i in d:
    if i == 0: continue
    if f[i - 1][3]: ans.append(i)

if len(ans) == 0: ans.append(0)

print(*ans)
