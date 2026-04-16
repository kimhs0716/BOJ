import sys
input = sys.stdin.readline

n, m = map(int, input().split())

edges = [set() for i in range(n + 1)]
for i in range(m):
    a, b = map(int, input().split())
    edges[a].add(b)
    edges[b].add(a)

result = []

already_used = [set() for i in range(n + 1)]
for i in range(1, n + 1):
    color = 1
    while color in already_used[i]:
        color += 1
    result.append(color)
    for nodes in edges[i]:
        already_used[nodes].add(color)

print(' '.join(map(str, result)))
