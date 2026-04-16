import sys
from collections import deque


def input():
    return sys.stdin.readline().rstrip()


class Graph:
    def __init__(self, n):
        self.node_size = n
        self.edge_size = 0
        self.adj = [dict() for i in range(n + 1)]

    def add_edge(self, src, dst, weight):
        if dst not in self.adj[src]:
            self.adj[src][dst] = []
        self.adj[src][dst].append(weight)
        self.edge_size += 1

    def get_edges(self, src, dst):
        return self.adj[src][dst]


def BFS(graph, start, goal):
    q = deque()
    q.append((start, 0))
    visited = set()
    visited.add(start)

    while q:
        v, d = q.popleft()
        if v == goal:
            return d
        # print(v, graph.adj[v])
        for u in graph.adj[v].keys():
            if u in visited: continue
            visited.add(u)
            q.append((u, d + min(graph.get_edges(v, u))))

    return -1


n = int(input())
s, g = map(int, input().split())
e = int(input())

graph = Graph(n)
for i in range(e):
    a, b = map(int, input().split())
    graph.add_edge(a, b, 1)
    graph.add_edge(b, a, 1)

print(BFS(graph, s, g))
