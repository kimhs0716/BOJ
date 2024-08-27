import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass

from collections import deque

dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

def bfs(arr, r, c, visited):
    queue = deque([(r, c)])
    visited.add((r, c))
    ret = 0
    while queue:
        ret += 1
        r, c = queue.popleft()
        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]
            if 0 > nr or 0 > nc: continue
            if len(arr) <= nr or len(arr[0]) <= nc: continue
            if arr[nr][nc] == 0: continue
            if (nr, nc) in visited: continue
            visited.add((nr, nc))
            queue.append((nr, nc))
    return ret


n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
visited = set()

cnt = 0
M = 0

for r in range(n):
    for c in range(m):
        if arr[r][c] == 1 and (r, c) not in visited:
            M = max(M, bfs(arr, r, c, visited))
            cnt += 1

print(cnt)
print(M)
