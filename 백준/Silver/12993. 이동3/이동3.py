import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


def ternary(n):
    if n == 0: return '0'
    ret = ''
    while n > 0:
        ret = str(n % 3) + ret
        n //= 3
    return ret

n, m = map(int, input().split())
n = ternary(n)
m = ternary(m)
l = max(len(n), len(m))
n = n.zfill(l)
m = m.zfill(l)
if {n, m} == {'0'}:
    print(1)
    exit(0)
for i in range(l):
    if {n[i], m[i]} != set('01'):
        print(0)
        break
else:
    print(1)
