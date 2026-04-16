import sys
input = lambda: sys.stdin.readline().rstrip()

from decimal import Decimal, getcontext
getcontext().prec = 30

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
    c1 += -x ** 3
    c2 += 3 * x ** 2 * (y - b)
    c3 += -3 * x * (y - b) ** 2
    c4 += (y - b) ** 3

# print(c1, c2, c3, c4)

f = make_f(c1, c2, c3, c4)
df = make_f(0, 3 * c1, 2 * c2, c3)

ans = solve(f, df)
print(ans)

