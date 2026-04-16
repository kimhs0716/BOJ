import sys
input = sys.stdin.readline

n = int(input())
aa, bb, cc, dd = [], [], [], []
for i in range(n):
    a, b, c, d = map(int, input().split())
    aa.append(a)
    bb.append(b)
    cc.append(c)
    dd.append(d)

m = dict()

for i in cc:
    for j in dd:
        if (i + j) not in m: m[i + j] = 0
        m[i + j] += 1

ans = 0
for i in aa:
    for j in bb:
        if (-i - j) in m:
            ans += m[-i - j]

print(ans)
