import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n, k = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))
s = sum(a)
t = sum(b)

for _ in range(k):
    if s == t:
        a[-1] += 1
        s += 1
    if s < t:
        t -= b.pop()
    else:
        s -= a.pop()

# print(s, t)
print(max(s, t))
