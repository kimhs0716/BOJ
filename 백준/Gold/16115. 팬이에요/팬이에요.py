import sys
import math
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
pts = []
max_d = -1

for _ in range(n):
    x, y = map(int, input().split())
    pts.append((x, y))
    d = x * x + y * y
    if d > max_d:
        max_d = d

arr = []
for x, y in pts:
    if x * x + y * y == max_d:
        ang = math.atan2(y, x)
        if ang < 0:
            ang += 2 * math.pi
        arr.append(ang)

arr.sort()
k = len(arr)

if k == 1:
    print("360.0")
    sys.exit(0)

ans = 0.0
for i in range(k - 1):
    ans = max(ans, arr[i + 1] - arr[i])
ans = max(ans, arr[0] + 2 * math.pi - arr[-1])

print(f"{ans * 180 / math.pi:.10f}")