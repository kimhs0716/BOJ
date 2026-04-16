import sys
input = lambda: sys.stdin.readline().rstrip()

from math import gcd
M = 0
n = int(input())
dic = {}
for _ in range(n):
    x, y = map(int, input().split())
    g = gcd(abs(x), abs(y))
    x //= g
    y //= g
    if (x, y) not in dic:
        dic[(x, y)] = 0
    dic[(x, y)] += 1
    M = max(M, dic[(x, y)])
print(M)
