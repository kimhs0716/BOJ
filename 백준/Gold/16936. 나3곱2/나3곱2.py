import sys
input = lambda: sys.stdin.readline().rstrip()

from pprint import pprint

n = int(input())
arr = list(map(int, input().split()))
adj = [[0] * n for _ in range(n)]

for i in range(n):
    for j in range(n):
        if arr[i] == arr[j] * 3 or arr[i] * 2 == arr[j]:
            adj[i][j] = 1

# pprint(adj)

def dfs(cur, visited, depth=0, path=None):
    if path is None:
        path = []
    # print(cur, path, depth)
    if depth == n - 1:
        print(*map(lambda x: arr[x], path))
        exit(0)
    for node in range(n):
        if adj[cur][node] == 1 and node not in visited:
            visited.add(node)
            path.append(node)
            dfs(node, visited, depth + 1, path)
            path.pop()
            visited.remove(node)

for i in range(n):
    visited = set()
    path = []
    visited.add(i)
    path.append(i)
    dfs(i, visited, 0, path)
