import sys
from random import random

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


from collections import Counter

ans = 0
n = int(input())
for _ in range(n):
    arr = list(map(int, input().split()))
    c = Counter(arr)
    if len(c) == 1:
        ans = max(ans, 5000 * (10 + c.most_common()[0][0]))
    elif len(c) == 2:
        if c.most_common()[0][1] == 3:
            ans = max(ans, 1000 * (10 + c.most_common()[0][0]))
        else:
            ans = max(ans, 500 * (4 + c.most_common()[0][0] + c.most_common()[1][0]))
    elif len(c) == 3:
        ans = max(ans, 100 * (10 + c.most_common()[0][0]))
    else:
        ans = max(ans, 100 * max(arr))
print(ans)
