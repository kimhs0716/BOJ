import sys
input = lambda: sys.stdin.readline()[:-1]

def cal(a, b):
    cnt = 0
    for i in range(4):
        cnt += a[i] != b[i]
    return cnt

for _ in range(int(input())):
    n = int(input())
    a = input().split()
    d = {}
    for i in a:
        if i not in d: d[i] = 0
        d[i] += 1
        if d[i] > 3: d[i] -= 1
    a = []
    for i, j in d.items():
        for _ in range(j): a.append(i)
    m = 1e9
    l = len(a)
    for i in range(l):
        for j in range(i + 1, l):
            for k in range(j + 1, l):
                m = min(m, cal(a[i], a[j]) + cal(a[j], a[k]) + cal(a[k], a[i]))
    print(m)
