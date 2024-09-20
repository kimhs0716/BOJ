import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()

def pprint(arr):
    for i in arr:
        print(i)
    print()

dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

def dfs(r, c, arr):
    stack = [(r, c)]
    visited = {(r, c)}
    while stack:
        r, c = stack.pop()
        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]
            if 1 <= nr < len(arr) - 1 and 1 <= nc < len(arr[0]) - 1:
                if arr[nr][nc] == 0: continue
                if (nr, nc) in visited: continue
                visited.add((nr, nc))
                stack.append((nr, nc))
    return visited

def count(arr):  # 0 or 1 or 2
    visited = None
    for i in range(1, len(arr) - 1):
        for j in range(1, len(arr[0]) - 1):
            if arr[i][j] != 0:
                visited = dfs(i, j, arr)
                break
        if visited is not None:
            break
    if visited is None:
        return 0
    for i in range(1, len(arr)- 1):
        for j in range(1, len(arr[0]) - 1):
            if arr[i][j] == 0: continue
            if (i, j) in visited: continue
            return 2
    return 1

n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
t = 0

# pprint(arr)

while True:
    t += 1
    narr = [arr[i][:] for i in range(n)]
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            if arr[i][j] == 0: continue
            cur = 0
            for k in range(4):
                nr = i + dr[k]
                nc = j + dc[k]
                if 0 <= nr < len(arr) and 0 <= nc < len(arr[0]):
                    cur += (arr[nr][nc] == 0)
            narr[i][j] -= min(cur, arr[i][j])
    arr = narr
    c = count(arr)
    # pprint(arr)
    if c == 0:
        t = 0
        break
    elif c == 1:
        continue
    else:
        break

print(t)
