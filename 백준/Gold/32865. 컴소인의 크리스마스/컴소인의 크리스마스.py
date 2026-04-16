import sys
input = lambda: sys.stdin.readline()[:-1]

import heapq


green = []
red = []

n = int(input())
for i in range(n):
    m = int(input())
    if m == 0:
        green.append(i + 1)
    else:
        red.append([m, i + 1])

heapq.heapify(red)
flag = True
ans = []

while True:
    if not green:
        flag = False
        break
    ans.append(green.pop())
    if not red:
        if green:
            flag = False
        break
    ans.append(red[0][1])
    red[0][0] -= 1
    if red[0][0] == 0:
        green.append(heapq.heappop(red)[1])


if not flag:
    print(-1)
else:
    print(*ans)
