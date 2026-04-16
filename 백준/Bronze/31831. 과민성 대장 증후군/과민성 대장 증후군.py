import sys
input = lambda: sys.stdin.readline().rstrip()


n, m = map(int, input().split())
arr = list(map(int, input().split()))

ans = 0
cur = 0
for i in arr:
    cur += i
    cur = max(0, cur)
    if cur >= m: ans += 1

print(ans)
