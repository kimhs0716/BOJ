import sys
input = lambda: sys.stdin.readline().rstrip()


INF = 10**18


n, k = map(int, input().split())
dp = [0] + [INF] * k
arr = map(int, input().split())
for x in arr:
    for i in range(k, -1, -1):
        if i-x < 0: break
        dp[i] = min(dp[i], dp[i-x]+1)

print(-1 if dp[k]==INF else dp[k])
