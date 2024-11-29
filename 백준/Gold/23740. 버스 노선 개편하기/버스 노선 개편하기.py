import sys
from random import random

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

arr.sort()

# print(arr)

ans = []

left, right, cost = arr[0]
for s, e, c in arr[1:]:
    if s > right:
        ans.append([left, right, cost])
        left = s
        right = e
        cost = c
    else:
        right = max(right, e)
        cost = min(cost, c)
ans.append([left, right, cost])

print(len(ans))
for i in ans:
    print(*i)
