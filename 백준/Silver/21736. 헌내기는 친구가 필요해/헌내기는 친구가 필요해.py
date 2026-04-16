from collections import deque

n, m = map(int, input().split())
arr = [input() for _ in range(n)]

for i in range(n):
    for j in range(m):
        if arr[i][j] == 'I':
            r, c = i, j

dr = (1, 0, -1, 0)
dc = (0, 1, 0, -1)

cnt = 0
queue = deque()
queue.append((r, c))
visited = set()
visited.add((r, c))
while queue:
    r, c = queue.popleft()
    for i in range(4):
        nr = r + dr[i]
        nc = c + dc[i]
        if nr < 0 or nr >= n: continue
        if nc < 0 or nc >= m: continue
        if arr[nr][nc] == 'X': continue
        if (nr, nc) in visited: continue
        if arr[nr][nc] == 'P': cnt += 1
        queue.append((nr, nc))
        visited.add((nr, nc))
print(cnt if cnt else 'TT')
