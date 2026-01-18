import sys
input = lambda: sys.stdin.readline().rstrip()


from math import gcd


a, b = map(int, input().split())
a, b = max(a, b), min(a, b)

if a==b:
    print("INF")
else:
    n = b*b
    d = a-b
    g = gcd(n, d)
    print(n//g, d//g)
