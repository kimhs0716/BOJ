import sys

input = lambda: sys.stdin.readline().rstrip()
inf = float('inf')

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


n = int(input())
arr = list(map(int, input().split()))

ans = 0

cur = 0
cnt = 0
for i in range(n):
    if arr[i] % 2 == cur: continue
    cnt += 1
    cur ^= 1
ans = max(ans, cnt)

cur = 1
cnt = 0
for i in range(n):
    if arr[i] % 2 == cur: continue
    cnt += 1
    cur ^= 1
ans = max(ans, cnt)

print(ans)