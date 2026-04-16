import sys

input = lambda: sys.stdin.readline().rstrip()
inf = 0x123456789

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
pp = int(input())
p = [tuple(map(int, input().split())) for _ in range(pp)]
p = set(p)

dp = [[[0, -inf] for __ in range(n + 1)] for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, n + 1):
        dp[i][j][0] = max(dp[i][j - 1][0], dp[i - 1][j][0]) + arr[i - 1][j - 1]
        dp[i][j][1] = max(dp[i][j - 1][1], dp[i - 1][j][1]) + arr[i - 1][j - 1]
        if (i, j) in p: dp[i][j][1] = max(dp[i][j][0], dp[i][j][1])

print(dp[n][n][1])
