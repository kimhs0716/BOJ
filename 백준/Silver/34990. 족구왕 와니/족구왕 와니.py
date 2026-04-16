import sys
input = lambda: sys.stdin.readline()[:-1]

ans = 0
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

kick = 1
for _ in range(m):
    s = 0
    idx = -1
    x, y = map(int, input().split())
    if kick==0:
        kick = 1
        continue
    for i in range(n):
        xx, yy, rr, ss = arr[i]
        if (x-xx)**2 + (y-yy)**2 <= rr**2 and arr[i][3] > s:
            s = arr[i][3]
            idx = i
    if idx == 0: ans += 1
    if idx == -1: kick = 0

print(ans)
