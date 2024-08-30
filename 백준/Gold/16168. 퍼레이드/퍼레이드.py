import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


v, e = map(int, input().split())
arr = [0] * (v + 1)
adj = [[] for _ in range(v + 1)]
for i in range(e):
    a, b = map(int, input().split())
    arr[a] += 1
    arr[b] += 1
    adj[a].append(b)
    adj[b].append(a)
flag = False
stack = [1]
visited = [True] + [False] * v
while stack:
    cur = stack.pop()
    for nxt in adj[cur]:
        if visited[nxt]: continue
        visited[nxt] = True
        stack.append(nxt)
if all(visited): flag = True

if len(list(filter(lambda x: x % 2, arr))) in (0, 2) and flag:
    print('YES')
else:
    print('NO')
