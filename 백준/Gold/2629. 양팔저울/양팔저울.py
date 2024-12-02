import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass



n = int(input())
arr = list(map(int, input().split()))

# dp[i][j] = i번째 추까지 사용하여 무게가 j인지 확인할 수 있는지
# j의 범위: -40000 ~ 40000 -> 80001가지
dp = [[False] * 80001 for _ in range(n)]
dp[0][40000] = True
dp[0][40000 + arr[0]] = True
dp[0][40000 - arr[0]] = True

for i in range(1, n):
    for j in range(80001):
        for k in (arr[i], -arr[i], 0):
            if not (0 <= j - k <= 80000): continue
            if dp[i - 1][j - k] == 1:
                dp[i][j] = True

m = int(input())
w = list(map(int, input().split()))
for ww in w:
    print('NY'[dp[n - 1][40000 + ww]], end=' ')
