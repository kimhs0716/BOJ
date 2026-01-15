import sys
input = lambda: sys.stdin.readline().rstrip()
MOD = 10**9+7
INF = float('inf')



n, k = map(int, input().split())
coin = set(int(input()) for _ in range(n))

dp = [0] + [INF]*k
for c in coin:
    for i in range(c, k+1):
        dp[i] = min(dp[i], dp[i-c]+1)

print(dp[k] if dp[k]!=INF else -1)
