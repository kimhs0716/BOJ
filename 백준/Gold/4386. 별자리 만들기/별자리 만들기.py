import sys
input = lambda: sys.stdin.readline().rstrip()

import heapq


inf = float('inf')

class Graph:
    def __init__(self, n):
        self.size = n
        self.adj = [dict() for _ in range(n+1)]

    def addEdge(self, src, dst, w):
        if dst not in self.adj[src]:
            self.adj[src][dst] = inf
            self.adj[dst][src] = inf
        self.adj[src][dst] = min(w, self.adj[src][dst])
        self.adj[dst][src] = min(w, self.adj[dst][src])


def MST(graph):
    visited = set()
    edges = []
    cur = 1
    visited.add(cur)
    ans = 0
    for dst, w in graph.adj[cur].items():
        heapq.heappush(edges, (w, dst))
    while len(visited) < graph.size:
        u = heapq.heappop(edges)
        while u[1] in visited:
            u = heapq.heappop(edges)
        visited.add(u[1])
        ans += u[0]
        for dst, w in graph.adj[u[1]].items():
            heapq.heappush(edges, (w, dst))
    return ans


n = int(input())
graph = Graph(n)
stars = []
for i in range(n):
    x, y = map(float, input().split())
    for j in range(len(stars)):
        xx, yy = stars[j]
        w = ((x - xx) ** 2 + (y - yy) ** 2) ** 0.5
        graph.addEdge(i + 1, j + 1, w)
    stars.append((x, y))
print(MST(graph))

