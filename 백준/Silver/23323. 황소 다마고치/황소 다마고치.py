import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


tc = int(input())
for _ in range(tc):
    n, m = map(int, input().split())
    ans = 0
    while n > 1:
        ans += 1
        n >>= 1
    print(ans + m + 1)
