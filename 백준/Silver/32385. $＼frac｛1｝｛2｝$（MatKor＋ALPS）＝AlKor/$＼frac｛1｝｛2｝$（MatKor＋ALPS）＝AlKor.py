import sys

input = lambda: sys.stdin.readline().rstrip()

def solve(n):
    k = n // 2

    if n % 2 == 0:
        ans = list(range(-k, 0)) + list(range(1, k + 1)) + [0]
    else:
        ans = list(range(-k, 0)) + list(range(1, k + 1)) + [(k + 1) * n, k + 1]

    print(*ans)

solve(int(input()))
