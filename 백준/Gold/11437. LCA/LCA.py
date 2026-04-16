import sys
from collections import deque

sys.setrecursionlimit(10**7)
input = sys.stdin.readline

class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [[] for _ in range(n + 1)]
        self.parents = [-1] * (n + 1)
        self.cache = {}
        self.depth = [0] * (n + 1)

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def BFS(self, root):
        visited = set()
        queue = deque([root])
        while queue:
            u = queue.popleft()
            visited.add(u)
            for v in self.adj[u]:
                if v not in visited:
                    queue.append(v)
                    self.parents[v] = u
                    self.depth[v] = self.depth[u] + 1

    def get_LCA(self, u, v):
        if u == v: return u
        if u > v: return self.get_LCA(v, u)
        if (u, v) in self.cache: return self.cache[(u, v)]
        if self.depth[v] < self.depth[u]:
            uu = self.parents[u]
            vv = v
        elif self.depth[v] > self.depth[u]:
            uu = u
            vv = self.parents[v]
        else:
            uu = self.parents[u]
            vv = self.parents[v]
        self.cache[(u, v)] = self.get_LCA(uu, vv)
        return self.cache[(u, v)]



n = int(input())
graph = Graph(n)
for i in range(n - 1):
    u, v = map(int, input().split())
    graph.add_edge(u, v)

graph.BFS(1)

m = int(input())
for i in range(m):
    u, v = map(int, input().split())
    print(graph.get_LCA(u, v))

