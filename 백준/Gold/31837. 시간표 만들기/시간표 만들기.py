import sys
input = lambda: sys.stdin.readline().rstrip()


from itertools import product as p


def get_time(d, s):
    hh, mm = map(int, s.split(':'))
    return (d - 1) * 1440 + hh * 60 + mm

n = int(input())
arr = []
for i in range(n):
    arr.append([(0, 0, 0)])
    ai = int(input())
    for _ in range(ai):
        c, d, s, e = input().split()
        c = int(c)
        d = int(d)
        s = get_time(d, s)
        e = get_time(d, e)
        arr[-1].append((c, s, e))

ans = 0
for i in p(*arr):
    s = sorted(i, key=lambda x: x[1])
    flag = True
    for j in range(n - 1):
        if s[j][2] > s[j + 1][1]:
            flag = False
    if flag == False: continue
    if sum(map(lambda x: x[0], s)) != 22: continue
    ans += 1

print(ans)
