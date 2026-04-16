import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


ans = 0
loss = 0
n = int(input())
arr = list(map(int, input().split()))

for i in range(n):
    if arr[i] > loss:
        ans += arr[i] - loss
        loss = 2 * arr[i]
    else:
        loss += arr[i]

print(ans)
