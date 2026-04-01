import sys
input = lambda: sys.stdin.readline().rstrip()


n, t = map(int, input().split())
arr = [tuple(map(float, input().split())) for _ in range(n)]

def total_time(lam):
    s = 0.0
    for a, b, c in arr:
        x = (lam - b) / (2 * a)
        if x < 0:
            x = 0.0
        elif x > t:
            x = t
        s += x
    return s

lo = 0
hi = max(b for a, b, c in arr)

for _ in range(1000):
    mid = (lo+hi) / 2
    if total_time(mid) > t:
        lo = mid
    else:
        hi = mid

lam = hi
ans = 0
for a, b, c in arr:
    x = (lam-b) / (2*a)
    if x < 0:
        x = 0
    elif x > t:
        x = t
    ans += a*x*x + b*x + c

print(ans / n)
