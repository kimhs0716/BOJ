import sys
input = lambda: sys.stdin.readline().rstrip()

import heapq

n = int(input())
arr = []
for i in map(int, input().split()):
    heapq.heappush(arr, i)

m, M = min(arr), max(arr)
ans = M - m
first_max = M

while True:
    t = heapq.heappop(arr)
    M = max(M, 2 * t)
    heapq.heappush(arr, 2 * t)
    m = arr[0]
    if M - m < ans: ans = M - m
    if m > first_max: break

print(ans)
