n, m = map(int, input().split())
a, b = dict(), dict()
for _ in range(m):
    i, j, k = input().split()
    if j == 'P':
        a[int(i)] = int(k)
    else:
        b[int(i)] = int(k)
m, M = 0, 0
for i in range(1, n + 1):
    if a.get(i, 0) == 1 and b.get(i, 1) == 0: m += 1
    if a.get(i, 1) == 1 and b.get(i, 0) == 0: M += 1
print(m, M)
