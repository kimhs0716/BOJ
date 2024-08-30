import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

import heapq

n, k = map(int, input().split())
arr = []
for i in range(n):
    a, b = map(int, input().split())
    arr.append([a, b, i])

arr.sort()

ans = dict()
pq = []

idx = 0
for t in range(1, 32):
    while idx < n and arr[idx][0] == t:
        heapq.heappush(pq, (arr[idx][1], arr[idx][2]))
        idx += 1
    cnt = 0
    # print(pq)
    while cnt < k and pq:
        b, _id = heapq.heappop(pq)
        ans[_id] = t
        cnt += 1

for i in range(n):
    print(ans[i])
