import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

def integral(f, a, b, steps):
    ret = 0
    dx = abs(b - a) / steps
    for i in range(steps):
        ret += dx * f(a + (2 * i + 1) * dx / 2)
    return ret

def make_f(a, b):
    def f(x):
        x /= a
        return b * (1 - x * x) ** 0.5
    return f

pi = 3.1415926535897932384626

for _ in range(int(input())):
    a1, b1 = map(int, input().split())
    a2, b2 = map(int, input().split())

    if a1 <= a2:
        print(pi * a1 * b1)
        continue
    if b2 <= b1:
        print(pi * a2 * b2)
        continue

    r1 = a1 / b1
    r2 = a2 / b2
    yy = (a1 * a1 - a2 * a2) / (r1 * r1 - r2 * r2)
    xx = a1 * a1 - r1 * r1 * yy
    x = xx ** 0.5
    y = yy ** 0.5

    f1 = make_f(a1, b1)
    f2 = make_f(b2, a2)

    ans = integral(f1, 0, x, 100000)
    ans += integral(f2, 0, y, 100000)
    ans -= x * y
    print(4 * ans)
