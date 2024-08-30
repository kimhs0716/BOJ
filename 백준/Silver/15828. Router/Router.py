import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

from collections import deque

n = int(input())
q = deque()
while True:
    x = int(input())
    if x == -1: break
    elif x == 0: q.popleft()
    elif len(q) < n: q.append(x)

if q:
    print(*q)
else:
    print('empty')
