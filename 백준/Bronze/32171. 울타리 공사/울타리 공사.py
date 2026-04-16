import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


INF = 0x7f7f7f
n = int(input())
Mx, My = -INF, -INF
mx, my = INF, INF
for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    Mx = max((Mx, x1, x2))
    My = max((My, y1, y2))
    mx = min((mx, x1, x2))
    my = min((my, y1, y2))
    print(2 * (Mx - mx + My - my))
