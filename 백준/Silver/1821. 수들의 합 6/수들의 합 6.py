import sys
input = lambda: sys.stdin.readline().rstrip()

from itertools import permutations as p

def dot(u, v):
    return sum(map(lambda x: x[0] * x[1], zip(u, v)))

n, f = map(int, input().split())
comb = [[0] * n for _ in range(n)]
for i in range(n):
    comb[i][0] = 1
    comb[i][i] = 1
    for j in range(1, i):
        comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1]
for i in p(range(1, n + 1)):
    if dot(comb[n - 1], i) == f:
        print(*i)
        break
