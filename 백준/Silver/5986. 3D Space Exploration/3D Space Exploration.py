import sys
input = lambda: sys.stdin.readline()[:-1]
sys.setrecursionlimit(10 ** 7)

n = int(input())

dx = (1, -1, 0, 0, 0, 0)
dy = (0, 0, 1, -1, 0, 0)
dz = (0, 0, 0, 0, 1, -1)
visited = [[[False] * n for _ in range(n)] for _ in range(n)]

def dfs(x, y, z):
    for i in range(6):
        nx = x + dx[i]
        ny = y + dy[i]
        nz = z + dz[i]
        if nx < 0 or nx >= n: continue
        if ny < 0 or ny >= n: continue
        if nz < 0 or nz >= n: continue
        if not arr[nx][ny][nz]: continue
        if visited[nx][ny][nz] == False:
            visited[nx][ny][nz] = True
            dfs(nx, ny, nz)

cnt = 0
arr = [[[i == '*' for i in input()] for _ in range(n)] for _ in range(n)]
for x in range(n):
    for y in range(n):
        for z in range(n):
            if arr[x][y][z] and visited[x][y][z] == False:
                cnt += 1
                visited[x][y][z] = True
                dfs(x, y, z)
print(cnt)
