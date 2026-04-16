import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n = int(input())
s = set()
a = 0
s.add(0)
for i in range(1, n + 1):
    if a - i in s or a < i:
        a += i
    else:
        a -= i
    s.add(a)

print(a)
