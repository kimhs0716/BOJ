import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.sizes = [1] * n

    def find(self, x):
        if self.parent[x] == x: return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y: return
        if self.sizes[x] < self.sizes[y]:
            x, y = y, x
        self.sizes[x] += self.sizes[y]
        self.parent[y] = x

    def is_same(self, x, y):
        return self.find(x) == self.find(y)

    def size(self, x):
        return self.sizes[self.find(x)]

for _ in range(int(input())):
    n = int(input())
    arr = []
    f = set()
    f_id = dict()
    for _ in range(n):
        arr.append(input().split())
        f.add(arr[-1][0])
        f.add(arr[-1][1])
    for i in f:
        f_id[i] = len(f_id)
    uf = UnionFind(len(f))
    # print(f)
    # print(f_id)
    for u, v in arr:
        u = f_id[u]
        v = f_id[v]
        uf.union(u, v)
        print(uf.size(u))
        # print(uf.sizes)
