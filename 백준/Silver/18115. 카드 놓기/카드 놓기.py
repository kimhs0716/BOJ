import sys
input = lambda: sys.stdin.readline()[:-1]

from collections import deque

class My_deque(deque):
    def push_2(self, item):
        t = self.popleft()
        self.appendleft(item)
        self.appendleft(t)

dq = My_deque()
n = int(input())
arr = reversed(list(map(int, input().split())))
card = iter(range(1, n + 1))

for i in arr:
    if i == 1:
        dq.appendleft(next(card))
    elif i == 2:
        dq.push_2(next(card))
    else:
        dq.append(next(card))

print(' '.join(map(str, dq)))
