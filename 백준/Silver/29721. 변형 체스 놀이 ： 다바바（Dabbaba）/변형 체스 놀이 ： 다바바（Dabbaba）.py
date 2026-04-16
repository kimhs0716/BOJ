import sys
input = lambda: sys.stdin.readline().rstrip()

n, k = map(int, input().split())
s = set()

dx = [0, 2, 0, -2]
dy = [2, 0, -2, 0]

d = set()
for _ in range(k):
    x, y = map(int, input().split())
    d.update(((x, y), ))

for x, y in d:
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 1 <= nx <= n and 1 <= ny <= n and (nx, ny) not in d:
            s.update(((nx, ny),))

print(len(s))
