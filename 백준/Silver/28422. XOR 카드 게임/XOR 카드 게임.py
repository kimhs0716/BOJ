import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
arr = [*map(int, input().split())]
dp = [0] * n

if n==1:
    print(0)
    exit()

if n==2:
    print((arr[0]^arr[1]).bit_count())
    exit()

dp[0] = -float('inf')
dp[1] = (arr[0]^arr[1]).bit_count()
dp[2] = (arr[0]^arr[1]^arr[2]).bit_count()
for i in range(3, n):
    dp[i] = dp[i-2] + (arr[i-1]^arr[i]).bit_count()
    dp[i] = max(dp[i], dp[i-3] + (arr[i-2]^arr[i-1]^arr[i]).bit_count())

print(dp[-1])
