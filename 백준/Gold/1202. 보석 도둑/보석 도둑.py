import sys, heapq
input = sys.stdin.readline

n, k = map(int, input().split())

arr = []
bags = []

for _ in range(n):
    m, v = map(int, input().split())
    arr.append((m, -v))
arr.sort(reverse=True)

for _ in range(k):
    bags.append(int(input()))
bags.sort()

ans = 0
pq = []
for c in bags:
    while arr and arr[-1][0] <= c:
        m, v = arr.pop()
        v = -v
        heapq.heappush(pq, (-v, m))
    if pq:
        v, m = heapq.heappop(pq)
        ans -= v

print(ans)
