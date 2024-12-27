import sys

input = lambda: sys.stdin.readline().rstrip()
inf = float('inf')

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


def score(n):
    return n * (n + 1) * (n + 1) // 2 - n * (n + 1) * (2 * n + 1) // 6

input()
s = input()
cnt = 0
ans = 0
for i in s:
    if i == '2': cnt += 1
    else:
        ans += score(cnt)
        cnt = 0

ans += score(cnt)
print(ans)
