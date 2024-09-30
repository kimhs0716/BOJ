import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

t = int(input())
l, r = map(int, input().split())
ans = int((l == r) * abs(l))

for _ in range(t - 1):
    # print(ans)
    ll, rr = map(int, input().split())
    ans += (ll == l) * abs(ll) + (rr == r) * abs(rr) + (ll == rr) * abs(ll)
    l, r = ll, rr

print(ans)
