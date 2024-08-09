import sys
input = lambda: sys.stdin.readline().rstrip()

mod = int(1e9) + 7
dp = [[0] * 10, [0] * 10]

tc = int(input())
for _ in range(tc):
    n = int(input())
    for i in range(10): dp[1][i] = 1
    for i in range(2, n + 1):
        if i >= len(dp):
            dp.append([0] * 10)
            s = 0
            for j in range(10):
                s = (s + dp[i - 1][j]) % mod
                dp[i][j] = s
        else:
            continue

    print(sum(dp[n]) % mod)
