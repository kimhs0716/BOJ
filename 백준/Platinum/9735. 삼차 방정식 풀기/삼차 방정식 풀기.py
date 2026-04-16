import sys
input = lambda: sys.stdin.readline().rstrip()

from decimal import Decimal

diff = Decimal('1e-4')

def f(x):
    res = Decimal(0)
    res += a
    res *= x
    res += b
    res *= x
    res += c
    res *= x
    res += d
    return res

def dis():
    return b * b - 4 * a * c

def divs(a, d):
    a = abs(a)
    d = abs(d)
    
    arr1 = []
    arr2 = []

    for i in range(1, int(a ** 0.5) + 3):
        if a % i == 0: arr1.append(i); arr1.append(a // i)
    for i in range(1, int(d ** 0.5) + 3):
        if d % i == 0: arr2.append(i); arr2.append(d // i)

    arr1 = set(arr1)
    arr2 = set(arr2)

    ans = [i // j for i in arr2 for j in arr1 if i % j == 0] + [0] + \
          [-i // j for i in arr2 for j in arr1 if i % j == 0]
    return ans

t = int(input())
for _ in range(t):
    a, b, c, d = map(int, input().split())
    for i in divs(a, d):
        if abs(f(i)) < diff: break
    b += a * i
    c += b * i
    D = dis()
    if D == 0:
        if abs(-b / (2 * a) - i) < diff:
            print(i)
        elif -b / (2 * a) > i:
            print(i, -b / (2 * a))
        else:
            print(-b / (2 * a), i)
    elif D < 0:
        print(i)
    else:
        x1 = (-b - D ** 0.5) / (2 * a)
        x2 = (-b + D ** 0.5) / (2 * a)

        if abs(x1 - i) < diff:
            print(i, x2)
        elif abs(x2 - i) < diff:
            print(x1, i)
        else:
            print(*sorted((x1, x2, i)))
