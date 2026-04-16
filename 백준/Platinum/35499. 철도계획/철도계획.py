import sys
input = lambda: sys.stdin.readline().rstrip()


n, m = map(int, input().split())
par = [i for i in range(n)]
sz = [1] * n

def find(x):
    if x==par[x]: return x
    par[x] = find(par[x])
    return par[x]

def join(x, y):
    x = find(x)
    y = find(y)
    if x==y: return
    if sz[x] < sz[y]:
        x, y = y, x
    sz[x] += sz[y]
    par[y] = x

def same(x, y):
    return find(x) == find(y)

edges = []
for _ in range(m):
    u, v, w = map(int, input().split())
    edges.append((w, u-1, v-1))

edges.sort(reverse=True)

ans = 0
check = [0] * n
for w, u, v in edges:
    if same(u, v):
        if check[find(u)]: continue
        check[find(u)] = 1
        ans += w
    else:
        if check[find(u)] and check[find(v)]:
            continue
        flag = check[find(u)] or check[find(v)]
        ans += w
        join(u, v)
        check[find(u)] |= flag
print(ans)
