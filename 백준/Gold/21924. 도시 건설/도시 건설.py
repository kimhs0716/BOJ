import heapq
from collections import deque
import sys

input = lambda: sys.stdin.readline().rstrip()


class Graph:
    def __init__(self, n):
        self.size = n
        self.edges = [dict() for _ in range(n + 1)]
        self.w = 0

    def add_edge(self, src, dst, w):
        self.edges[src][dst] = w
        self.edges[dst][src] = w
        self.w += w


def mst(graph):
    n = graph.size
    ans = 0
    pq = []
    cnt = 1
    visited = {1}
    for d, w in graph.edges[1].items():
        heapq.heappush(pq, (w, 1, d))

    while cnt < n:
        while True:
            if not pq:
                return float('inf')
            p = pq[0]
            if p[2] in visited:
                heapq.heappop(pq)
            else:
                break
        p = heapq.heappop(pq)
        ans += p[0]
        visited.add(p[2])
        cnt += 1
        for d, w in graph.edges[p[2]].items():
            heapq.heappush(pq, (w, p[2], d))

    return ans


n, m = map(int, input().split())
graph = Graph(n)
for _ in range(m):
    a, b, w = map(int, input().split())
    graph.add_edge(a, b, w)

ans = graph.w - mst(graph)
if ans == float('-inf'): print(-1)
else: print(ans)
