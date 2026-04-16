import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n = int(input())
s = list(input())

c, p = [], []
for i in range(n):
    if s[i] == 'P': p.append(i)
    elif s[i] == 'C': c.append(i)

for i in range(min(len(p), len(c))):
    c[i], p[i] = p[i], c[i]

for i in c: s[i] = 'C'
for i in p: s[i] = 'P'

print(''.join(s))
