import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
arr = []
for _ in range(n):
    arr.append(tuple(map(int, input().split())))

if n <= 2:
    print(*arr[0])
    exit(0)

m = 1e10
ans = (0, 0)

for i in range(n):
    Md = 0
    for j in range(n):
        if i == j: continue
        d = (arr[i][0] - arr[j][0]) ** 2 + (arr[i][1] - arr[j][1]) ** 2
        if d > Md:
            # print(Md, d)
            Md = d
    # print(Md)
    if m > Md:
        ans = arr[i]
        m = Md

print(*ans)

