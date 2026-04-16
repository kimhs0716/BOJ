class Vector:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
    def __neg__(self):
        return Vector(-self.x, -self.y, -self.z)
    def __add__(self, v):
        return Vector(self.x + v.x, self.y + v.y, self.z + v.z)
    def __sub__(self, v):
        return self + (-v)
    def __mul__(self, v):
        if isinstance(v, Vector):
            return self.x * v.x + self.y * v.y + self.z * v.z
        return Vector(self.x * v, self.y * v, self.z * v)
    def __truediv__(self, i):
        return self * (1 / i)
    def distance(self, v):
        return ((self.x - v.x) ** 2 + (self.y - v.y) ** 2 + \
                (self.z - v.z) ** 2) ** 0.5
    def __repr__(self):
        return f'Vector({self.x}, {self.y}, {self.z})'

def perpendicular(a, b, c):
    return a + (b - a) * ((b - a) * (c - a)) / ((b - a) * (b - a))

arr = tuple(map(int, input().split()))
a = arr[:3]
b = arr[3:6]
c = arr[6:]
a, b, c = map(lambda x: Vector(*x), (a, b, c))

h = perpendicular(a, b, c)

if h.x < min(a.x, b.x) or h.x > max(a.x, b.x):
    print(min(c.distance(a), c.distance(b)))
else:
    print(c.distance(h))
