import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())

arr = list(map(int, input().split()))
arr.sort()
dq = deque(arr)

ans = 0
while len(dq) >= 2:
    while len(dq) >= 2 and dq[0] + dq[-1] < m:
        dq.popleft()
    if len(dq) >= 2:
        ans += 1
        dq.popleft()
        dq.pop()

print(ans)

