import sys

input = sys.stdin.readline


class Node:
    def __init__(self, a, b, data=None):
        self.a = a
        self.b = b
        if data is None: data = (0, 0)
        self.data = data

class SegTree:
    def __init__(self, n, f=None):
        if f is None: f = lambda a, b: a + b
        self.n = n
        self.size = 1
        while self.size < n:
            self.size <<= 1
        self.tree = [Node(0, 0) for i in range(self.size << 1)]
        self.func = f
        idx = 1
        self.tree[idx].a = 0
        self.tree[idx].b = self.size
        t = self.size
        while idx < self.size:
            idx <<= 1
            t >>= 1
            for i in range(idx):
                self.tree[idx + i].a = i * t
                self.tree[idx + i].b = (i + 1) * t

    def print(self):
        i = 1
        while i <= self.size:
            print(' '.join(map(lambda x: str(x.data), self.tree[i : i << 1])))
            i <<= 1

    def update(self, idx, data):
        idx += self.size
        self.tree[idx].data = data
        idx >>= 1
        while idx > 0:
            self.tree[idx].data = self.func(self.tree[idx << 1].data, self.tree[(idx << 1) + 1].data)
            idx >>= 1

    def get(self, a, b, idx=1):
        mid = (self.tree[idx].a + self.tree[idx].b) >> 1
        if self.tree[idx].a == a and self.tree[idx].b == b:
            return self.tree[idx].data
        if a < mid < b:
            left = self.get(a, mid, idx << 1)
            right = self.get(mid, b, (idx << 1) + 1)
            return self.func(left, right)
        elif mid <= a:
            return self.get(a, b, (idx << 1) + 1)
        else:
            return self.get(a, b, idx << 1)


n = int(input())

tree = SegTree(n, lambda x, y: tuple(sorted((*x, *y), reverse=True)[:2]))

arr = list(map(int, input().split()))

for i in range(n):
    tree.update(i, (arr[i], 0))

# tree.print()

m = int(input())
for _ in range(m):
    a, b, c = map(int, input().split())
    if a == 1:
        tree.update(b - 1, (c, 0))
        # tree.print()
    elif a == 2:
        print(sum(tree.get(b - 1, c)))
