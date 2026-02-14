import sys
input = lambda: sys.stdin.readline().rstrip()


def f(n):
    n = str(n)
    s = sum(map(lambda x: int(x)&1, n))
    l = len(n)
    if l == 1: return s, s
    if l == 2:
        x, y = f(int(n[0]) + int(n[1]))
        return s+x, s+y
    m = 10**18
    M = 0
    for i in range(1, l-1):
        for j in range(i+1, l):
            a = n[:i]
            b = n[i:j]
            c = n[j:]
            x, y = f(int(a)+int(b)+int(c))
            m = min(m, x)
            M = max(M, y)
    return s+m, s+M


n = int(input())
print(*f(n))
