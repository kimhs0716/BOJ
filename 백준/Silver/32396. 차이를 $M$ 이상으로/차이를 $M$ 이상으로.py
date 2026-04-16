import sys

input = lambda: sys.stdin.readline().rstrip()
inf = float('inf')

n, m = map(int, input().split())
arr = list(map(int, input().split()))

ans = 0
t = inf

for i in range(n):
    if abs(t - arr[i]) < m:
        ans += 1
        arr[i] = inf
    t = arr[i]

print(ans)
