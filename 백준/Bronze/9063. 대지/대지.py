import sys
input = sys.stdin.readline
x, y = (10000, -10000), (10000, -10000)
for _ in range(int(input())):
    nx, ny = map(int, input().split())
    x = min(x[0], nx), max(x[1], nx)
    y = min(y[0], ny), max(y[1], ny)
print((x[1] - x[0]) * (y[1] - y[0]))
