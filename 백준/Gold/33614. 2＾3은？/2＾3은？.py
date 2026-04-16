import sys
input = lambda: sys.stdin.readline()[:-1]


mod = int(1e9+7)
for _ in range(int(input())):
    p, q, r = map(int, input().split())
    print((min(q, r) + p - 1) % mod)
