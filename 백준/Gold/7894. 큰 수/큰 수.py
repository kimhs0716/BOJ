import sys
input = lambda: sys.stdin.readline().rstrip()

from math import log10

p = 10000

dp = [0]
cur = 0
for i in range(1, int(1e7) + 1):
    cur += log10(i)
    if i % p == 0:
        dp.append(cur)

for i in range(int(input())):
    m = int(input())
    ans = dp[m // p]
    for i in range(m // p * p + 1, m + 1):
        ans += log10(i)
    print(int(ans) + 1)
