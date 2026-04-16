import sys

input = sys.stdin.readline


class Vector2d:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vector2d(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector2d(self.x - other.x, self.y - other.y)

    def __mul__(self, other):
        return self.x * other.x + self.y * other.y

    def __repr__(self):
        return f'({self.x}, {self.y})'

    def __gt__(self, other):
        if self.y == other.y:
            return self.x > other.x
        return self.y > other.y

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y


def sig(a):
    if a == 0: return 0
    if a < 0: return -1
    return 1


def cos(x, y):
    return x * x / (x * x + y * y) * sig(x)


def ccw(v1, v2, v3):
    v2 -= v1
    v3 -= v1
    return (v2.x * v3.y) - (v2.y * v3.x)


n = int(input())

arr = []
for _ in range(n):
    v = Vector2d(*map(int, input().split()))
    arr.append(v)

p = min(arr)
for i in range(n):
    arr[i] -= p

zero = Vector2d(0, 0)

for i in range(n):
    if arr[i] == zero:
        del arr[i]
        break
arr.sort(key=lambda v: ((-cos(v.x, v.y)), v.x ** 2 + v.y ** 2))
arr.append(zero)

stack = [Vector2d(0, 0), arr[0]]

for i in range(1, n):
    stack.append(arr[i])
    while len(stack) >= 3 and ccw(stack[-3], stack[-2], stack[-1]) <= 0:
        stack.pop()
        stack.pop()
        stack.append(arr[i])

print(len(stack) - 1)
