import sys
input = lambda: sys.stdin.readline().rstrip()

sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass

class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [set() for _ in range(n)]
        self.root = None
        self.sizes = [-1] * n
        self.visited = set()

    def add_edge(self, u, v):
        self.adj[u].add(v)
        self.adj[v].add(u)

    def dfs(self, u):
        if self.sizes[u] == -1:
            ret = 1
            for child in self.adj[u]:
                if child in self.visited: continue
                self.visited.add(child)
                ret += self.dfs(child)
            self.sizes[u] = ret
        return self.sizes[u]


    def set_root(self, r):
        self.root = r
        self.visited.add(self.root)
        self.dfs(self.root)

    def solve(self, node):
        return self.dfs(node)

n, root, q = map(int, input().split())
graph = Graph(n + 1)
for _ in range(n - 1):
    u, v = map(int, input().split())
    graph.add_edge(u, v)

graph.set_root(root)

for _ in range(q):
    node = int(input())
    print(graph.solve(node))
