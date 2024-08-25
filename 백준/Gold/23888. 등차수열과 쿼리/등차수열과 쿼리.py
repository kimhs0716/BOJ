import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass

from math import gcd

a, d = map(int, input().split())

f = lambda n: a + d * (n - 1)
s = lambda l, r: (f(l) + f(r)) * (r - l + 1) // 2

q = int(input())

for i in range(q):
    c, l, r = map(int, input().split())
    if c == 1:
        print(s(l, r))
    else:
        if l == r:
            print(f(l))
        else:
            print(gcd(d, f(l)))
