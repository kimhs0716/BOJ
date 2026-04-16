import math
import sys
input = sys.stdin.readline

n, b = map(int, input().split())
Sx, Sy = 0, 0
for i in range(n):
    x, y = map(int, input().split())
    Sx += x
    Sy += y

Sy -= b * n
g = math.gcd(Sx, Sy)

if Sx == 0: print('EZPZ')
else:
    Sx //= g
    Sy //= g

    if Sx == 1:
        print(Sy)
    elif Sx == -1:
        print(-Sy)
    else:
        if Sx < 0:
            Sx *= -1
            Sy *= -1
        print(f'{Sy}/{Sx}')