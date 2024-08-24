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

n, m = map(int, input().split())
uf = UnionFind(n + 1)
for _ in range(m):
    c, a, b = map(int, input().split())
    if c == 0:
        uf.union(a, b)
    else:
        print("YES" if uf.is_same(a, b) else "NO")
