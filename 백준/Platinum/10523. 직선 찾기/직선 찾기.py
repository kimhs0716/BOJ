import sys
input = lambda: sys.stdin.readline().rstrip()


import random


n = int(input())
if n==1:
    print("possible")
    exit(0)
p = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

ITERS = 75

for _ in range(ITERS):
    i = random.randint(0, n-2)
    j = random.randint(i+1, n-1)
    a = arr[i]
    b = arr[j]
    cnt = 0
    dx1 = a[0]-b[0]
    dy1 = a[1]-b[1]
    for x, y in arr:
        dx2 = x-a[0]
        dy2 = y-a[1]
        if dx1*dy2 == dy1*dx2:
            cnt += 1
    if 100*cnt >= p*n:
        print("possible")
        break
else:
    print("impossible")


