import sys
input = lambda: sys.stdin.readline()[:-1]

import heapq

pq1 = []
pq2 = []

n = int(input())
for _ in range(n):
    q, p = map(int, input().split())
    heapq.heappush(pq1, (-q, p))
    heapq.heappush(pq2, (p, -q))

q, p = heapq.heappop(pq1)
print(-q, p, end=' ')
q, p = heapq.heappop(pq1)
print(-q, p)

p, q = heapq.heappop(pq2)
print(-q, p, end=' ')
p, q = heapq.heappop(pq2)
print(-q, p)
