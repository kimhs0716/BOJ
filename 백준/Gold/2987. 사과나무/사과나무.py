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

def cross(a, b, c):
    return (a.x * b.y + b.x * c.y + c.x * a.y) - \
           (b.x * a.y + c.x * b.y + a.x * c.y)

t = [Vector(*map(int, input().split())) for _ in '123']
S = 0.5 * abs(cross(t[0], t[1], t[2]))

cnt = 0
n = int(input())
for _ in range(n):
    p = Vector(*map(int, input().split()))
    c1, c2, c3 = \
        cross(t[0], p, t[1]), cross(t[1], p, t[2]), cross(t[2], p, t[0])
    if c1 * c2 >= 0 and c2 * c3 >= 0 and c3 * c1 >= 0:
        cnt += 1
print(S)
print(cnt)
