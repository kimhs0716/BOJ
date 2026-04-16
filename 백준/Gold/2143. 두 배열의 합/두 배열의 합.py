import sys
input = lambda: sys.stdin.readline()[:-1]

t = int(input())

n = int(input())
a = list(map(int, input().split()))
csa = [0]
for i in range(n): csa.append(csa[-1] + a[i])

m = int(input())
b = list(map(int, input().split()))
csb = [0]
for i in range(m): csb.append(csb[-1] + b[i])

da = dict()
db = dict()

for i in range(n + 1):
    for j in range(i + 1, n + 1):
        da[csa[j] - csa[i]] = da.get(csa[j] - csa[i], 0) + 1

for i in range(m + 1):
    for j in range(i + 1, m + 1):
        db[csb[j] - csb[i]] = db.get(csb[j] - csb[i], 0) + 1

ans = 0
for i in da.keys():
    ans += da[i] * db.get(t - i, 0)

print(ans)
