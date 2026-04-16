import sys
sys.setrecursionlimit(10 ** 7)

def dfs(x, y):
    global arr, visited, r, c
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= c: continue
        if ny < 0 or ny >= r: continue
        if (nx, ny) in visited: continue
        if arr[ny][nx] == 0: continue
        visited.add((nx, ny))
        dfs(nx, ny)

dx = (1, 1, 1, -1, -1, -1, 0, 0)
dy = (-1, 0, 1, -1, 0, 1, -1, 1)

r, c = map(int, input().split())
arr = [list(map(int, input().split())) for i in range(r)]

visited = set()

cnt = 0
for i in range(r):
    for j in range(c):
        if arr[i][j] == 1 and (j, i) not in visited:
            dfs(j, i)
            cnt += 1
print(cnt)