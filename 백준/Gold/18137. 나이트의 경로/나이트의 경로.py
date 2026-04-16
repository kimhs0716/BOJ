import sys
input = sys.stdin.readline

dr = (-2, -1, -2, 1, -1, 2, 1, 2)
dc = (-1, -2, 1, -2, 2, -1, 2, 1)


def get(r, c):
    return (r + c - 1) * (r + c - 2) // 2 + r

visited = set()

cur = 1
r, c = 1, 1
k = int(input())
for _ in range(k):
    visited.add(cur)
    flag = False
    for i in range(8):
        nr = r + dr[i]
        nc = c + dc[i]
        if nr < 1 or nc < 1: continue
        if get(nr, nc) in visited: continue
        break
    else:
        break
    r, c = nr, nc
    cur = get(r, c)
print(cur)


