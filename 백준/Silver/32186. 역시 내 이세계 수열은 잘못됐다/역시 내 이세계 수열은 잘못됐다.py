import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

n, k = map(int, input().split())
arr = list(map(int, input().split()))

ans = 0
for i in range(n // 2):
    diff = abs(arr[i] - arr[n - i - 1])
    ans += min(diff // k + diff % k, diff // k + 1 + k - (diff % k))

print(ans)

