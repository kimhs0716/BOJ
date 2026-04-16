from collections import deque
import sys
input = lambda: sys.stdin.readline().rstrip()

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

def bfs(start, arr):
    visited = [[0] * len(arr[0]) for i in range(len(arr))]
    q = deque([start + (0, )])
    visited[start[0]][start[1]] = 1
    while q:
        r, c, d = q.popleft()
        for i in range(4):
            nr, nc = r + dr[i], c + dc[i]
            if 0 <= nr < len(arr) and 0 <= nc < len(arr[0]):
                if arr[nr][nc] >= 3: return d + 1
                if arr[nr][nc] != 1 and visited[nr][nc] == 0:
                    q.append((nr, nc, d + 1))
                    visited[nr][nc] = 1
    return -1

n, m = map(int, input().split())
arr = [list(map(int, list(input()))) for _ in range(n)]
start = (-1, -1)
for r in range(n):
    for c in range(m):
        if arr[r][c] == 2:
            start = (r, c)
ans = bfs(start, arr)
if ans == -1:
    print("NIE")
else:
    print("TAK\n{}".format(ans))
