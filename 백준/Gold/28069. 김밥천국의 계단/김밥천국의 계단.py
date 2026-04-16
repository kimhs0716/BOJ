import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import deque

n, k = map(int, input().split())
visited = set()
q = deque()
visited.add(0)
q.append((0, 0))

while q:
    cur, time = q.popleft()
    if cur == n and time <= k:
        print('minigimbob')
        break
    if time > k: continue
    if cur > n: continue
    if cur + 1 not in visited:
        q.append((cur + 1, time + 1))
        visited.add(cur + 1)
    if cur * 3 // 2 not in visited:
        q.append((cur * 3 // 2, time + 1))
        visited.add(cur * 3 // 2)
else:
    print('water')
