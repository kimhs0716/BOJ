from collections import deque

n, m = map(int, input().split())
parents = [set() for _ in range(n+1)]
children = [set() for _ in range(n+1)]
ans = []

for _ in range(m):
    t, *arr = map(int, input().split())
    for i in range(t - 1):
        parents[arr[i + 1]].add(arr[i])
        children[arr[i]].add(arr[i + 1])

q = deque()
for i in range(1, n + 1):
    if len(children[i]) == 0:
        q.append(i)

if not q:
    print(0)

else:
    while q:
        x = q.popleft()
        ans.append(x)
        for y in parents[x]:
            children[y].remove(x)
            if not children[y]:
                q.append(y)

if len(ans) == n:
    print(*reversed(ans), sep='\n')
else:
    print(0)


