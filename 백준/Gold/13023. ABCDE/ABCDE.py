import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()

def solve(arr, cur=0, depth=0, visited=None):
    # print(depth, visited)
    if visited is None:
        visited = {0}
    if depth == 5: return 1
    for i in adj[cur]:
        if i in visited: continue
        visited.add(i)
        if solve(arr, i, depth + 1, visited): return 1
        visited.remove(i)
    return 0

n, m = map(int, input().split())
adj = [set() for _ in range(n + 1)]
for i in range(n + 1):
    adj[0].add(i)
    adj[i].add(0)
for _ in range(m):
    a, b = map(int, input().split())
    a += 1
    b += 1
    adj[a].add(b)
    adj[b].add(a)
# print(*adj, sep='\n')
print(solve(adj))
