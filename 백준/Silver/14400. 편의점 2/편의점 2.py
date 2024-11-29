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

left = (n - 1) // 2
right = n // 2

arr.sort()
x = arr[n // 2][0]

arr.sort(key=lambda x: (x[1], x[0]))
y = arr[n // 2][1]

ans = 0
for xx, yy in arr:
    ans += abs(x - xx) + abs(y - yy)

print(ans)
