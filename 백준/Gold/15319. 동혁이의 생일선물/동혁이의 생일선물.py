import sys
input = lambda: sys.stdin.readline().rstrip()

mod = int(1e9 + 7)

n = int(input())

ret = 0
for _ in range(n):
    x, k = map(int, input().split())
    t = 1
    while k:
        if k & 1:
            ret = (ret + t) % mod
        k >>= 1
        t = t * x % mod

print(ret)
