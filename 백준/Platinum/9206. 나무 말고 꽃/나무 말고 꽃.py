import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

from decimal import Decimal, getcontext

pi = Decimal('3.14159265')
# getcontext().prec = 10

def make_f(a, b):
    def f(x):
        ex = (-x * x).exp()
        return a * a * ex * ex + 2 * a * b * ex * x.sqrt()
    return f

def volume(a, b, h):
    f = make_f(a, b)
    result = b * b * h * h / 2
    steps = Decimal(5000)
    dx = 1 / steps
    for i in range(int(h * steps)):
        result += f(dx * (2 * i + 1) / 2) * dx
    return result * pi

vv, n = map(Decimal, input().split())
n = int(n)

ans = [float('inf'), -1]

for i in range(n):
    a, b, h = map(Decimal, input().split())
    v = volume(a, b, h)
    # print(v)
    absvv = abs(v - vv)
    if absvv < ans[0]:
        ans[0] = absvv
        ans[1] = i

print(ans[1])

