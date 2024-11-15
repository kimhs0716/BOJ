import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n = int(input())
m = int(input())

print(2 * (n - 1) * (m - 1))
