import sys
input = lambda: sys.stdin.readline().rstrip()


def find(arr, rr, cc, path):
    if cc==c-1: return path
    ret = []
    for dr in (-1, 0, 1):
        nr = rr+dr
        if nr<0 or nr>=r: continue
        if arr[nr][cc+1]: continue
        if (nr, cc+1) in vis: continue
        vis.add((nr, cc+1))
        path.append(nr)
        ret = find(arr, nr, cc+1, path)
        if ret: return ret
        path.pop()
    return ret


r, c = map(int, input().split())
arr = []
for _ in range(r):
    t = input()
    arr.append([])
    for i in range(c):
        arr[-1].append(int(t[i]=='x'))

ans = 0
vis = set()
for i in range(r):
    vis.add((i, 0))
    path = find(arr, i, 0, [i])
    # print(i, path)
    if path:
        for j in range(c):
            arr[path[j]][j] = 1
        ans += 1
print(ans)
