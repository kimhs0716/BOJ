import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


a2, a1, a0 = map(int, input().split())
c = int(input())
n0 = int(input())

a2 -= c

if a2 > 0: ans = 0
elif a2 == 0:
    if a1 <= 0 and a1 * n0 + a0 <= 0: ans = 1
    else: ans = 0
else:
    D = a1 ** 2 - 4 * a2 * a0
    if (a2 * n0 ** 2 + a1 * n0 + a0 <= 0 and 2 * a2 * n0 + a1 <= 0) or D <= 0: ans = 1
    else: ans = 0

print(ans)
