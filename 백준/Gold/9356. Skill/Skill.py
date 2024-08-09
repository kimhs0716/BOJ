import sys
input = lambda: sys.stdin.readline().rstrip()

mod = int(1e9) + 7

tc = int(input())
for _ in range(tc):
    n = int(input())
    dp = [[0] * 10 for _ in range(n + 1)]
    for i in range(10): dp[1][i] = 1
    for i in range(2, n + 1):
        s = 0
        for j in range(10):
            s = (s + dp[i - 1][j]) % mod
            dp[i][j] = s

    print(sum(dp[n]) % mod)
