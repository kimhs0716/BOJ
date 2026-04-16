import sys
input = sys.stdin.readline

from collections import Counter

x = int(input())
k = int(input())

if k == 0:
    y = str(x)[0]
    y *= len(str(x))
    if int(y) < x:
        y = int(y[0]) + 1
        y = str(y) * len(str(x))
else:
    ans = float('inf')
    n = len(str(x))
    for i in range(10):
        t = str(i) * n
        for j in range(n):
            for m in range(10):
                tt = t[:j] + str(m) + t[j + 1:]
                if x <= int(tt):
                    ans = min(ans, int(tt))
    y = ans

print(y)
