n, l = map(int, input().split())
for i in range(l, 101):
    a1 = 2 * n - i * (i - 1)
    if a1 % (2 * i) or a1 < 0: continue
    a1 //= 2 * i
    for j in range(i):
        print(a1 + j, end=' ')
    exit(0)
print(-1)
