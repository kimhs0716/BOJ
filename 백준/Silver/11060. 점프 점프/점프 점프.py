import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


from collections import deque

n = int(input())
arr = list(map(int, input().split()))

q = deque([(0, 0)])
visited = set()

while q:
    cur, t = q.popleft()
    # print(cur, t)
    if cur == n - 1:
        print(t)
        break
    for i in range(1, arr[cur] + 1):
        if cur + i not in visited:
            visited.add(cur + i)
            q.append((cur + i, t + 1))
else:
    print(-1)
