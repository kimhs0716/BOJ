import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass



n = (int(input()))
cost = map(int, input().split())
value = map(int, input().split())
arr = list(zip(cost, value))
ans = [0, 0]

for i in range(1 << n):
    cur = [0, 0]
    for j in range(n):
        if i & 1:
            cur[0] += arr[j][0]
            cur[1] += arr[j][1]
        i >>= 1
    if cur[0] < 100 and cur[1] > ans[1]:
        ans = cur[:]

print(ans[1])
