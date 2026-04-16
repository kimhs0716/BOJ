import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


mod = int(1e9) + 7

n, h = map(int, input().split())
arr = list(map(int, input().split()))

# dp[h] -> 높이 h 일때의 가짓수
dp = [0] * (h + 1)
dp[0] = 1

for i in range(1, h + 1):
    for j in arr:
        if j > i: continue
        dp[i] = (dp[i] + dp[i - j]) % mod

print(dp[-1])
