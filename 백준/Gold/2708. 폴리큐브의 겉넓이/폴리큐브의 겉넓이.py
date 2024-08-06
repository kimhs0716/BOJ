import sys
input = lambda: sys.stdin.readline()[:-1]

dx = (-1, 1, 0, 0, 0, 0)
dy = (0, 0, -1, 1, 0, 0)
dz = (0, 0, 0, 0, -1, 1)

t = int(input())
for _ in range(t):
    n = int(input())
    arr = []
    for i in range((n + 7) // 8):
        arr.extend(input().split())
    for i in range(n):
        arr[i] = list(map(int, arr[i].split(',')))
    visited = set()
    ans = 0
    flag = True
    for i in range(n):
        x, y, z = arr[i]
        cur = 6
        if (x, y, z) in visited:
            flag = False
            break
        for j in range(6):
            nx, ny, nz = x + dx[j], y + dy[j], z + dz[j]
            if (nx, ny, nz) in visited:
                cur -= 2
        if i != 0 and cur == 6:
            flag = False
            break
        ans += cur
        visited.add((x, y, z))
    if flag:
        print(ans)
    else:
        print("NO", i + 1)
