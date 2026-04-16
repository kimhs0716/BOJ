import sys

input = sys.stdin.readline

def solve(n, m):
    s = 2 * n * n * (m * m * n + 2 * m * (m * m - 1) / 3)
    cnt = (2 * n * m) ** 2
    return s, cnt

tc = int(input())
for _ in range(tc):
    m, n = map(int, input().split())
    s, cnt = solve(n, m)
    print(int(s * 100 // cnt / 10 + 0.5) / 10)
