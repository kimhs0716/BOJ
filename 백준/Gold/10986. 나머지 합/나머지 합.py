import sys
input = lambda: sys.stdin.readline().rstrip()


n, m = map(int, input().split())
cnt = [0] * m
cnt[0] = 1
arr = [*map(int, input().split())]
s = 0
for i in range(n):
    s = (s+arr[i])%m
    cnt[s] += 1
ans = 0
for i in range(m):
    ans += cnt[i] * (cnt[i]-1) // 2
print(ans)
