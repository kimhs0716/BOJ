import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


class Graph:
    def __init__(self):
        self.nodes = []
        self.adj = []

    def add_node(self, l, r):
        self.adj.append(set())
        n = len(self.nodes)
        for idx, (ll, rr) in enumerate(self.nodes):
            if l < ll < r or l < rr < r: self.adj[idx].add(n)
            if ll < l < rr or ll < r < rr: self.adj[-1].add(idx)
        self.nodes.append([l, r])

    def dfs(self, src, dst):
        visited = {src}
        stack = [src]
        while stack:
            cur = stack.pop()
            if cur == dst: return 1
            for nxt in self.adj[cur]:
                if nxt not in visited:
                    visited.add(nxt)
                    stack.append(nxt)
        return 0


n = int(input())
g = Graph()
for _ in range(n):
    a, b, c = map(int, input().split())
    if a == 1:
        g.add_node(b, c)
    else:
        print(g.dfs(b - 1, c - 1))
