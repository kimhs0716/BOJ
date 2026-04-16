import heapq
n, m = map(int, input().split())
arr = []
list(map(lambda x: heapq.heappush(arr, x), map(int, input().split())))
for _ in range(m):
    a = heapq.heappop(arr) + heapq.heappop(arr)
    heapq.heappush(arr, a)
    heapq.heappush(arr, a)
print(sum(arr))
