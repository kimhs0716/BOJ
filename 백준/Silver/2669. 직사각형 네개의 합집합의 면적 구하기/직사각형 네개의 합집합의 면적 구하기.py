arr = [[0] * 101 for _ in range(101)]

for i in range(4):
    a, b, c, d = map(int, input().split())
    for x in range(a, c):
        for y in range(b, d):
            arr[y][x] = 1

print(sum(map(sum, arr)))
