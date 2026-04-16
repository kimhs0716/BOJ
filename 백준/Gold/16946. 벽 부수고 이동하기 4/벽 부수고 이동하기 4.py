import sys
input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(int(2e6))

dr = (0, 1, 0, -1)
dc = (1, 0, -1, 0)


def dfs(arr, r, c, idx=-1):
    global size, visited
    if visited[r][c] is not None: return
    if idx == -1:
        idx = len(size)
        size.append(0)
    size[idx] += 1
    visited[r][c] = idx

    for i in range(4):
        nr = r + dr[i]
        nc = c + dc[i]
        if nr < 0 or nr >= n: continue
        if nc < 0 or nc >= m: continue
        if arr[nr][nc] == '1': continue
        if visited[nr][nc] is not None: continue
        dfs(arr, nr, nc, idx)


n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]

size = []
visited = [[None] * m for _ in range(n)]

for r in range(n):
    for c in range(m):
        if board[r][c] == '0':
            dfs(board, r, c)


for r in range(n):
    for c in range(m):
        if board[r][c] == '0': print('0', end='')
        else:
            s = set()
            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]
                if nr < 0 or nr >= n: continue
                if nc < 0 or nc >= m: continue
                if board[nr][nc] == '1': continue
                s.add(visited[nr][nc])
            print((sum(map(lambda x: size[x], s)) + 1) % 10, end='')
    print()
