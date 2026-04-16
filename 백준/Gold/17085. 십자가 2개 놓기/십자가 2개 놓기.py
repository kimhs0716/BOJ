def check(arr, i, j):
    if arr[i][j] == '.':
        return 0
    ret = 1
    c = 1
    while True:
        flag = True
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = i + dx * c, j + dy * c
            if 0 <= nx < len(arr) and 0 <= ny < len(arr[0]):
                if arr[nx][ny] == '.':
                    flag = False
                    break
            else:
                flag = False
                break
        if not flag: break
        ret += 4
        c += 1
    return ret

def overlap(i, j, t, k, l, tt):
    t //= 4
    tt //= 4
    if min(abs(i - k), abs(j - l)) > min(t, tt): return False
    return abs(i - k) + abs(j - l) <= t + tt

r, c = map(int, input().split())

arr = [input() for _ in range(r)]
m = [[0] * c for _ in range(r)]

ans = 0

for i in range(r):
    for j in range(c):
        m[i][j] = check(arr, i, j)

for i in range(r):
    for j in range(c):
        t = m[i][j]
        if t == 0: continue
        for k in range(r):
            for l in range(c):
                # print(i, j, k, l)
                if k == i and l == j: continue
                if m[k][l] == 0: continue
                tt = m[k][l]
                ttt = t
                while overlap(i, j, ttt, k, l, tt):
                    # print(ttt, tt)
                    if ttt > tt: ttt -= 4
                    else: tt -= 4
                ans = max(ans, ttt * tt)
print(ans)