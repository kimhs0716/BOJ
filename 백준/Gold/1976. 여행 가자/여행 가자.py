import sys
input = lambda: sys.stdin.readline().rstrip()

def union(u, v):
    u = find(u)
    v = find(v)
    parents[u] = v

def find(u):
    if parents[u] != u:
        parents[u] = find(parents[u])
    return parents[u]

n = int(input())
m = int(input())

parents = [i for i in range(n + 1)]

for u in range(1, n + 1):
    adj = map(int, input().split())
    for v in range(1, n + 1):
        if next(adj) == 1: union(u, v)

travel = map(int, input().split())
if len(set(map(find, travel))) == 1:
    print('YES')
else:
    print('NO')
