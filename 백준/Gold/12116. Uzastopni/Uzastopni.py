import sys
input = lambda: sys.stdin.readline().rstrip()

def divs(n):
    ret = set()
    i = 1
    while i * i <= n:
        if n % i == 0:
            ret.add(i)
            ret.add(n // i)
        i += 1
    ret.remove(n)
    return ret

n = int(input())

for i in divs(2 * n):
    if 2 * n % i == 0:
        j = 2 * n // i
        k = j - 1
        if k < 1: continue
        if (i - k) % 2 != 0: continue
        a = (i - k) // 2
        if a < 1: continue
        print(a, a + k)
