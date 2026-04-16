def dfs(x, y):
    arr[y][x] = 0
    ret = 1
    for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
        nx = x + dx
        ny = y + dy
        if 0 <= nx and nx < 3 and 0 <= ny and ny < 3 and arr[ny][nx] == 1:
            ret += dfs(nx, ny)
    return ret

for _ in range(int(input())):
    arr = []
    for __ in range(3):
        arr.append(list(map(lambda x: int(x == 'O'), input())))
    ans = []
    for i in range(3):
        for j in range(3):
            if arr[i][j] == 1:
                ans.append(dfs(j, i))
    ans.sort()
    ans = str(len(ans)) + ' ' + ' '.join(map(str, ans))
    print(int(ans.strip() == input().strip()))
