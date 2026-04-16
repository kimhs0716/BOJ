import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


def dis(a, b):
    return ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** 0.5

class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))

    def find(self, x):
        if self.p[x] == x: return x
        self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        self.p[px] = py

    def is_same(self, x, y):
        return self.find(x) == self.find(y)

class Graph:
    def __init__(self, n):
        self.n = n
        self.nodes = []
        self.edges = []
        for i in range(n):
            x, y = map(int, input().split())
            for j, (xx, yy) in enumerate(self.nodes):
                self.add_edge(i, j, dis((xx, yy), (x, y)))
            self.nodes.append((x, y))

    def add_edge(self, u, v, w):
        self.edges.append((w, u, v))

    def MST(self, selected):
        self.edges.sort()
        uf = UnionFind(self.n)
        ret = 0
        for u, v in selected:
            uf.union(u, v)
        for w, u, v in self.edges:
            if uf.is_same(u, v): continue
            uf.union(u, v)
            ret += w
        return ret

n, m = map(int, input().split())
graph = Graph(n)
selected = []
for _ in range(m):
    a, b = map(int, input().split())
    selected.append((a - 1, b - 1))
print(f'{graph.MST(selected):.2f}')
