import sys

try:
    sys.stdin = open("boj.in", "r", encoding="utf-8")
    sys.stdout = open("boj.out", "w", encoding="utf-8")
except:
    pass

input = lambda: sys.stdin.readline().rstrip()

from collections import Counter

n = int(input())
arr = [[*map(int, input().split())] for _ in range(n)]

sarr = [[Counter()] * (n+1) for _ in range(n+1)]
for i in range(1, n+1):
    for j in range(1, n+1):
        sarr[i][j] = sarr[i-1][j] + sarr[i][j-1] - sarr[i-1][j-1] + Counter({arr[i-1][j-1]: 1})

# for i in range(1, n+1):
#     for j in range(1, n+1):
#         print(sarr[i][j], end=' ')
#     print()

for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    t = sarr[c][d] + sarr[a-1][b-1] - sarr[c][b-1] - sarr[a-1][d]
    print(len(t))