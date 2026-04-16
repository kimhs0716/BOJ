import sys
input = lambda: sys.stdin.readline()[:-1]

n = int(input())
arr = []
p = 0

for _ in range(n):
    arr.append(tuple(map(int, input().split())))
    p += arr[-1][1]

arr.sort()
s = 0
for x, a in arr:
    s += a
    if 2 * s >= p:
        break
print(x)
