import sys
input = lambda: sys.stdin.readline().rstrip()

from itertools import permutations as p

ans = float('inf')
ans_route = None

n, m = map(int, input().split())
adj = [[float('inf')] * (n + 1) for _ in range(n + 1)]
for _ in range(m):
    a, b, w = map(int, input().split())
    adj[a][b] = w

for route in p(range(1, n + 1)):
    cur = route[0]
    t = 0
    for node in route[1:]:
        t = max(t, adj[cur][node])
        cur = node
    t = max(t, adj[cur][route[0]])
    if t < ans:
        ans = t
        ans_route = route

if ans == float('inf'):
    print(-1)
else:
    print(ans)
    print(*ans_route)

