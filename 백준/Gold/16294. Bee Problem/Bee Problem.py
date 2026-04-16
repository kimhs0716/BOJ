import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6 + 100)

def dfs(r, c):
    global visited, arr
    ans = 1
    dr = (-1, 0, 1, -1, 0, 1)
    if r % 2 == 0:
        dc = (-1, -1, -1, 0, 1, 0)
    else:
        dc = (0, -1, 0, 1, 1, 1)
    for i in range(6):
        nr = r + dr[i]
        nc = c + dc[i]
        if nr < 0 or nr >= len(arr): continue
        if nc < 0 or nc >= len(arr[0]): continue
        if (nr, nc) in visited: continue
        if arr[nr][nc] == '#': continue
        visited.add((nr, nc))
        ans += dfs(nr, nc)
    return ans

visited = set()
h, n, m = map(int, input().split())
arr = [input().split() for _ in range(n)]

l = []
for i in range(n):
    for j in range(m):
        if (i, j) in visited: continue
        if arr[i][j] == '#': continue
        visited.add((i, j))
        l.append(dfs(i, j))

l.sort()
cnt = 0
while h > 0:
    cnt += 1
    h -= l.pop()
print(cnt)
