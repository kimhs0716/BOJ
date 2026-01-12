import sys
input = lambda: sys.stdin.readline()[:-1]


def f(n, l):
    k = int(n)
    for i in n[:l]:
        if i == '0': continue
        if k % int(i): return False
    return True

n = input()
l = len(n)
if f(n, l): print(n)
else:
    for k in range(1, 10):
        for j in range(10**k):
            t = n + str(j).zfill(k)
            if f(t, l):
                print(t)
                exit(0)
