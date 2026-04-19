import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
l, r = 0, 0
s = 0
ans = 0

while r<n:
    r += 1
    s += r
    while s>n:
        s -= l
        l += 1
    if s==n: ans += 1

print(ans)
