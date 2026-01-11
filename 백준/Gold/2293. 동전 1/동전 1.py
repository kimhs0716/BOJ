import sys
input = lambda: sys.stdin.readline()[:-1]


n, k = map(int, input().split())
arr = [int(input()) for _ in range(n)]
dp = [1]+[0]*k

for x in arr:
    ndp = dp
    for i in range(x):
        for j in range(i+x, k+1, x):
            ndp[j] += dp[j-x]
    dp = ndp
    # print(dp)

print(dp[k])
