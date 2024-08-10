import sys
input = lambda: sys.stdin.readline()[:-1]

def union(u, v):
    u = find(u)
    v = find(v)
    parents[u] = v

def find(u):
    if parents[u] != u:
        parents[u] = find(parents[u])
    return parents[u]

n, m = map(int, input().split())
parents = [i for i in range(n + 1)]

true = list(map(int, input().split()))[1:]
for i in true:
    union(0, i)

parties = [list(map(int, input().split()))[1:] for _ in range(m)]

for i in range(m):
    party = parties[i]
    for p in party: union(p, party[0])

ans = 0
for party in parties:
    ans += all(map(lambda x: find(x) != find(0), party))

print(ans)
