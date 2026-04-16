import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()


inf = 10 ** 10

def dist(a, b):
    return ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** 0.5

class Graph:
    def __init__(self, n):
        self.n = n
        self.edges = [[0] * (n + 2) for _ in range(n + 2)]
        self.nodes = [(0, 0)]
        self.dist = [inf] * (n + 2)

    def dijkstra(self, start):
        visited = [False] * (self.n + 2)
        self.dist[start] = 0
        pq = [(0, start)]
        while pq:
            _, cur = heapq.heappop(pq)
            if visited[cur]: continue
            visited[cur] = True
            for nxt in range(self.n + 2):
                if self.dist[cur] + self.edges[cur][nxt] < self.dist[nxt]:
                    self.dist[nxt] = self.dist[cur] + self.edges[cur][nxt]
                    heapq.heappush(pq, (self.dist[nxt], nxt))




a, b = map(int, input().split())
n = int(input())
g = Graph(n)
g.nodes.append((a, b))
for i in range(n):
    x, y = map(int, input().split())
    g.nodes.append((x, y))

g.edges[0][1] = dist(g.nodes[0], g.nodes[1])
g.edges[1][0] = g.edges[0][1]
for i in range(2, n + 2):
    g.edges[0][i] = max(dist(g.nodes[0], g.nodes[i]) - 1, 0)
    g.edges[1][i] = max(dist(g.nodes[1], g.nodes[i]) - 1, 0)
    g.edges[i][0] = g.edges[0][i]
    g.edges[i][1] = g.edges[1][i]
    for j in range(2, i):
        g.edges[i][j] = max(dist(g.nodes[j], g.nodes[i]) - 2, 0)
        g.edges[j][i] = g.edges[i][j]

g.dijkstra(0)

print(g.dist[1])
