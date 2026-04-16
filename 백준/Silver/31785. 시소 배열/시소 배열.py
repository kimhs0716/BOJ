import sys
from collections import deque

input = lambda: sys.stdin.readline()[:-1]

q1, q2 = deque(), deque()
s1, s2 = 0, 0

n = int(input())
for _ in range(n):
    i, *x = map(int, input().split())
    if i == 1:
        q2.append(x[0])
        s2 += x[0]
    else:
        if s1 <= s2:
            print(s1)
            q1.clear()
            s1 = 0
        else:
            print(s2)
            q2 = q1.copy()
            s2 = s1
            q1.clear()
            s1 = 0

    while len(q1) + 1 < len(q2):
        q1.append(q2.popleft())
        s2 -= q1[-1]
        s1 += q1[-1]

print(*q1, *q2)
