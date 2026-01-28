import sys
input = lambda: sys.stdin.readline().rstrip()


from collections import deque


MAX = 200001
n, m = map(int, input().split())
vis = [0] * MAX
prev = [-1] * MAX
vis[n] = 1

q = deque([n])
while q:
    cur = q.popleft()
    if cur == m:
        break
    if cur-1>=0 and vis[cur-1]==0:
        vis[cur-1] = 1
        prev[cur-1] = cur
        q.append(cur-1)
    if cur+1<MAX and vis[cur+1]==0:
        vis[cur+1] = 1
        prev[cur+1] = cur
        q.append(cur+1)
    if cur*2<MAX and vis[cur<<1]==0:
        vis[cur<<1] = 1
        prev[cur<<1] = cur
        q.append(cur<<1)

ans = [m]
while prev[m] != -1:
    m = prev[m]
    ans.append(m)

print(len(ans)-1)
print(*ans[::-1])
