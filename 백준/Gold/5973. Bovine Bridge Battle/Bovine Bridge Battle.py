import sys
input = lambda: sys.stdin.readline()[:-1]

n = int(input())
points = []
for _ in range(n):
    x, y = map(int, input().split())
    points.append((x, y))

mid = dict()
for i in range(n):
    for j in range(i + 1, n):
        x1, y1 = points[i]
        x2, y2 = points[j]
        m = ((x1 + x2) / 2, (y1 + y2) / 2)
        mid[m] = mid.get(m, 0) + 1

ans = 0
for k in mid.keys():
    ans += mid[k] * (mid[k] - 1) // 2
print(ans)

