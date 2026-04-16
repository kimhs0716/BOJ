from decimal import Decimal

n, x = input().split()
n = int(n)
x = Decimal(x)

g = {'A+': 4.5, 'A0': 4.0, 'B+': 3.5, 'B0': 3.0,
     'C+': 2.5, 'C0': 2.0, 'D+': 1.5, 'D0': 1.0, 'F': 0.0}

s = 0
ss = Decimal(0)
for i in range(n - 1):
    a, b = input().split()
    s += int(a)
    ss += int(a) * Decimal(g[b])
k = int(input())
s += k
goal = x * s

for i in reversed(g):
    if int((ss + k * Decimal(g[i])) * 100 / s) > int(x * 100):
        print(i)
        break
else:
    print('impossible')
