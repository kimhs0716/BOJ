import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()

def __pow(n, r, mod):
    if r == 0: return 1
    ret = __pow(n, r >> 1, mod)
    ret = ret * ret % mod
    if r & 1: ret = ret * n % mod
    return ret

dr = [0, 1, 0, -1]
dc = [-1, 0, 1, 0]

mod = int(1e9 + 7)

n, m = map(int, input().split())
arr = [input() for _ in range(n)]

cnt = 0
for r in range(n):
    for c in range(m):
        flag = True
        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]
            if 0 <= nr < n and 0 <= nc < m:
                if arr[r][c] != arr[nr][nc]:
                    flag = False
                    break
        if flag: cnt += 1

print(__pow(2, cnt, mod))
