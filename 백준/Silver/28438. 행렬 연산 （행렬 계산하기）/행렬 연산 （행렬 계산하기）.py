import sys
input = lambda: sys.stdin.readline().strip()

n, m, q = map(int, input().split())

arr = [[0] * m for _ in range(n)]

query = [[0] * n, [0] * m]
for _ in range(q):
    x, a, v = map(int, input().split())
    query[x - 1][a - 1] += v


for i in range(n):
    for j in range(m):
        arr[i][j] += query[0][i]
        arr[i][j] += query[1][j]

for i in arr:
    print(*i)
