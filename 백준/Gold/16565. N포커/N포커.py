import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


def solve(n, m):
    global cache
    if n <= 0 or m < 0 or n < m: return 0
    if (n, m) not in cache:
        ret = 0
        for i in range(1, m // 4 + 1):
            a = n - 4 * i
            b = m - 4 * i
            ret += comb(n // 4, i) * (comb(a, b) - solve(a, b)) % 10007
        cache[(n, m)] = ret % 10007
    return cache[(n, m)]

from math import comb
cache = dict()

n = int(input())
print(solve(52, n))
