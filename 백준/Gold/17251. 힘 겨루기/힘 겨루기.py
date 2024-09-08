import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n = int(input())
arr = list(map(int, input().split()))
left = [arr[0]]
right = [arr[-1]]
for i in range(1, n):
    left.append(max(left[-1], arr[i]))
    right.append(max(right[-1], arr[-i - 1]))
right.reverse()

cnt = [0, 0]
for i in range(n - 1):
    if left[i] > right[i + 1]: cnt[0] += 1
    elif left[i] < right[i + 1]: cnt[1] += 1

if cnt[0] < cnt[1]: print('B')
elif cnt[0] > cnt[1]: print('R')
else: print('X')
