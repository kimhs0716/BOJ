import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


n = int(input())
p = int(input())
ans = p

if n >= 5: ans = min(ans, p - 500)
if n >= 10: ans = min(ans, p * 0.9)
if n >= 15: ans = min(ans, p - 2000)
if n >= 20: ans = min(ans, p * 0.75)

print(max(int(ans), 0))
