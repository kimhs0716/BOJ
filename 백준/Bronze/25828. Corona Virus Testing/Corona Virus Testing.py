import sys

input = lambda: sys.stdin.readline().rstrip()
inf = float('inf')

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


g, p, t = map(int, input().split())
ans1 = g * p
ans2 = g + p * t

ans = 0 if ans1 == ans2 else 1 if ans1 < ans2 else 2
print(ans)
