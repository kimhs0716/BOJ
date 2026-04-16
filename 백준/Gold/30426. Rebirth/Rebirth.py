import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
arr = [tuple(map(int, input().split())) for _ in range(k)]
l = int(input())
larr = set([int(input()) for _ in range(l)])

s = [m]
for idx in range(k):
    ns = []
    visited = set()
    for i in s:
        if i in larr: continue
        g = (i + arr[idx][0]) % n
        if g not in visited:
            visited.add(g)
            ns.append(g)
        y = (i + arr[idx][1]) % n
        if y not in visited:
            visited.add(y)
            ns.append(y)
    s = ns

if not all(ns):
    print('utopia')
else:
    print('dystopia')
