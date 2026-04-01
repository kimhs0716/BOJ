import sys
input = lambda: sys.stdin.readline().rstrip()


from collections import deque


c, r = map(int, input().split())
arr = []
x_cnt = 0
x, y = -1, -1
gx, gy = -1, -1
for i in range(r):
    arr.append([])
    s = input()
    for j in range(c):
        if s[j]=='#': arr[-1].append(-1)
        elif s[j]=='.': arr[-1].append(-2)
        elif s[j]=='X':
            arr[-1].append(x_cnt)
            x_cnt += 1
        elif s[j]=='S':
            x, y = i, j
            arr[-1].append(-2)
        else:
            gx, gy = i, j
            arr[-1].append(-2)            

vis = [[[-1] * (c) for _ in range(r)] for _ in range(1<<x_cnt)]

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

q = deque()
q.append((x, y, 0))
vis[0][x][y] = 0
time = 1
while q:
    sz = len(q)
    for _ in range(sz):
        x, y, mask = q.popleft()
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx<0 or nx>=r: continue
            if ny<0 or ny>=c: continue
            if arr[nx][ny]==-1: continue
            if arr[nx][ny] != -2: nmask = mask | (1<<arr[nx][ny])
            else: nmask = mask
            if vis[nmask][nx][ny] != -1: continue
            vis[nmask][nx][ny] = time
            q.append((nx, ny, nmask))
    time += 1

print(vis[(1<<x_cnt)-1][gx][gy])
