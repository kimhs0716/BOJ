import sys
input = lambda: sys.stdin.readline()[:-1]


n = int(input())
f, s = [], []
for _ in range(n):
    a, b = map(float, input().split())
    f.append(a)
    s.append(b)

f.sort(reverse=True)
s.sort(reverse=True)

ans = 0
fi, si = 0, 0
fs, ss = 0, 0
for i in range(2*n):
    if si==n or (fi!=n and (fs<ss or (fs==ss and f[fi]>s[si]))):
        fs += f[fi]
        fi += 1
    else:
        ss += s[si]
        si += 1
    ans = max(ans, min(fs, ss)-(i+1))

print("%.4lf"%ans)
