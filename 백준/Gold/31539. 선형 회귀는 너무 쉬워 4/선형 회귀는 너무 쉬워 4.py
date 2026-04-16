import sys
input = lambda: sys.stdin.readline().rstrip()

from decimal import Decimal, getcontext
getcontext().prec = 50

diff = Decimal('1e-10')

def solve(f, df):
    x = Decimal(0)
    for _ in range(500):
        # print(x)
        x -= f(x) / (df(x) + diff)
    return x

def make_f(c1, c2, c3, c4):
    def f(x):
        return c1 * x ** 3 + c2 * x ** 2 + c3 * x + c4
    return f

n, b = map(int, input().split())
c1, c2, c3, c4 = 0, 0, 0, 0

for _ in range(n):
    x, y = map(int, input().split())
    c1 += 4 * x ** 4
    c2 += -12 * x ** 3 * (y - b)
    c3 += 12 * x ** 2 * (y - b) ** 2
    c4 += -4 * x * (y - b) ** 3

f = make_f(c1, c2, c3, c4)
df = make_f(0, 3 * c1, 2 * c2, c3)

ans = solve(f, df)
print(ans)

