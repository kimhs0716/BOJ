import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

n, A = map(int, input().split())
d = dict()
for i in range(n):
    x, y, w = map(int, input().split())
    r = (x * x + y * y) ** 0.5
    d[r] = d.get(r, 0) + w
arr = list(d.items())
arr.sort()
arr.append([float('inf')])

ans = 0
_sum = 0
_sum2 = 0
for i in range(len(arr) - 1):
    _sum += arr[i][1]
    _sum2 += arr[i][0] * arr[i][1]
    _cur = arr[i][0]
    _next = arr[i + 1][0]
    c = _sum / (2 * A)
    if _cur <= c <= _next:
        cc = -A * c ** 2 + c * _sum - _sum2
        if cc > ans: ans = cc

print(ans)
