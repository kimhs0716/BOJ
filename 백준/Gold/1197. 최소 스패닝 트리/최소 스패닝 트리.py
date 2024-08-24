import sys
input = lambda: sys.stdin.readline().rstrip()

sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, x):
        if self.parent[x] == x: return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root1 = self.find(x)
        root2 = self.find(y)
        self.parent[root1] = root2

    def is_same(self, x, y):
        return self.find(x) == self.find(y)

class Graph:
    def __init__(self, n):
        self.INF = 9876543210
        self.n = n
        # self.adj = [[self.INF] * n for _ in range(n)]
        self.edges = []

    def add_edge(self, u, v, w):
        # self.adj[u][v] = min(self.adj[u][v], w)
        # self.adj[v][u] = min(self.adj[v][u], w)
        self.edges.append((u, v, w))

    def MST(self):
        ret = 0
        uf = UnionFind(self.n)
        edges = sorted(self.edges, key=lambda x: x[2], reverse=True)
        while edges:
            u, v, w = edges.pop()
            if uf.is_same(u, v): continue
            uf.union(u, v)
            ret += w
        return ret

v, e = map(int, input().split())
graph = Graph(v)
for _ in range(e):
    u, v, w = map(int, input().split())
    graph.add_edge(u - 1, v - 1, w)

print(graph.MST())