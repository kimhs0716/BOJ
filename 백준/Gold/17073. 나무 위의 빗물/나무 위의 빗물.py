import sys
input = sys.stdin.readline
n, w = map(int, input().split())
adj = [0] * (n + 1)
for _ in range(n - 1):
    a, b = map(int, input().split())
    adj[a] += 1
    adj[b] += 1
cnt = 0
for i in range(2, n + 1):
    if adj[i] == 1:
        cnt += 1
print(w / cnt)