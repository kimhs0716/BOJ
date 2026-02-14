import sys
input = lambda: sys.stdin.readline().rstrip()


from copy import deepcopy


n, k = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
s, x, y = map(int, input().split())


def check(arr, r, c):
    ret = 10000
    for i in range(4):
        nr = r+dr[i]
        nc = c+dc[i]
        if nr<0 or nr>=n: continue
        if nc<0 or nc>=n: continue
        if arr[nr][nc]: ret = min(ret, arr[nr][nc])
    return ret


dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]
for _ in range(s):
    narr = deepcopy(arr)
    updated = False
    for r in range(n):
        for c in range(n):
            if arr[r][c] == 0: continue
            for i in range(4):
                nr = r+dr[i]
                nc = c+dc[i]
                if nr<0 or nr>=n: continue
                if nc<0 or nc>=n: continue
                if narr[nr][nc]: continue
                if check(arr, nr, nc) == arr[r][c]:
                    narr[nr][nc] = arr[r][c]
                    updated = True
    if not updated: break
    arr = narr

print(arr[x-1][y-1])
