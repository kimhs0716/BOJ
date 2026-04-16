import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()

arr = []
n = int(input())
for _ in range(n):
    s, t, *a = input().split()
    arr.extend(a)
c = Counter(arr)
c = c.most_common(2)
if len(c) >= 2 and c[0][1] == c[1][1]:
    print(-1)
else:
    print(c[0][0])