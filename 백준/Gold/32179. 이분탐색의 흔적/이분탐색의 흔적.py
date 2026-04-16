import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


from math import factorial as f

mod = int(1e9 + 7)
def comb(n, r):
    return (f(n) // (f(n - r) * f(r))) % mod

n, k = map(int, input().split())
arr = list(map(int, input().split())) + [-1]

ans = [0] + [-1] * n + [101]
s, e = 0, n - 1
for i in range(k):
    mid = s + (e - s) // 2
    ans[mid + 1] = arr[i]

    if arr[i + 1] < arr[i]:
        e = mid - 1
    else:
        s = mid + 1

if ans[1] != -1: ans[0] = ans[1] - 1
if ans[-2] != -1: ans[-1] = ans[-2] + 1

result = 1
left = 0
for i in range(1, len(ans)):
    if ans[i] == -1: continue
    # ans[left] + 1 ~ ans[i] - 1
    t = ans[i] - ans[left] - 1
    result *= comb(t, i - left - 1)
    result %= mod
    left = i

print(result)
