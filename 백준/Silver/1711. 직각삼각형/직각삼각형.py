import sys
input = lambda: sys.stdin.readline().rstrip()

class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __neg__(self):
        return Vector(-self.x, -self.y)
    def __add__(self, v):
        return Vector(self.x + v.x, self.y + v.y)
    def __sub__(self, v):
        return self + (-v)
    def __mul__(self, v):
        if isinstance(v, Vector):
            return self.x * v.x + self.y * v.y
        return Vector(self.x * v, self.y * v)
    def __rmul__(self, v):
        if isinstance(v, Vector):
            return self.x * v.x + self.y * v.y
        return Vector(self.x * v, self.y * v)
    def __truediv__(self, i):
        return self * (1 / i)
    def distance(self, v):
        return ((self.x - v.x) ** 2 + (self.y - v.y) ** 2) ** 0.5
    def __repr__(self):
        return f'Vector({self.x}, {self.y})'

n = int(input())
arr = [Vector(*map(int, input().split())) for _ in range(n)]
cnt = 0

for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            if (arr[i] - arr[j]) * (arr[i] - arr[k]) == 0 or \
               (arr[j] - arr[i]) * (arr[j] - arr[k]) == 0 or \
               (arr[k] - arr[i]) * (arr[k] - arr[j]) == 0:
                cnt += 1

print(cnt)
