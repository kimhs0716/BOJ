import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

visited = [[0] * m for _ in range(n)]

cnt = 0
for i in range(n):
    for j in range(m):
        if arr[i][j] == 0 and visited[i][j] == 0:
            cnt += 1
            stack = [(i, j)]
            visited[i][j] = 1
            while stack:
                r, c = stack.pop()
                # print(r, c)
                for idx in range(4):
                    nr = (r + dr[idx]) % n
                    nc = (c + dc[idx]) % m
                    if visited[nr][nc] == 1: continue
                    if arr[nr][nc] == 1: continue
                    stack.append((nr, nc))
                    visited[nr][nc] = 1

print(cnt)
