import sys
input = lambda: sys.stdin.readline().rstrip()


import heapq


n, m = map(int, input().split())
adj = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    adj[u-1].append(v-1)
    adj[v-1].append(u-1)
arr = [int(input()) for _ in range(n)]

vis = [1] + [0]*(n-1)
s = arr[0]
pq = [(arr[nxt], nxt) for nxt in adj[0]]
heapq.heapify(pq)

while pq:
    x, y = heapq.heappop(pq)
    if vis[y]: continue

    if x >= s: break
    vis[y] = 1
    s += x
    for nxt in adj[y]:
        if vis[nxt]: continue
        heapq.heappush(pq, (arr[nxt], nxt))

print(s)

