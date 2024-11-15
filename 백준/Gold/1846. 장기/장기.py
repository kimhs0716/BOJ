import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n = int(input())

if n <= 3:
    print(-1)
else:
    ans = [i % n + 1 for i in range(1, n + 1)]
    if n % 2 == 0: ans[n // 2 - 1], ans[-1] = ans[-1], ans[n // 2 - 1]
    else: ans[-1], ans[-3] = ans[-3], ans[-1]
    print(*ans, sep='\n')
