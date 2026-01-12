import sys
input = lambda: sys.stdin.readline()[:-1]


def get_p(n):
    ret = []
    if n%2==0:
        ret.append(2)
        while n%2==0:
            n >>= 1
    i = 3
    while i*i<=n:
        if n%i==0:
            ret.append(i)
            while n%i==0:
                n //= i
        i += 2
    if n!=1:
        ret.append(n)
    return ret


def f(p, mask):
    ret = 1
    for i in range(len(p)):
        if (mask>>i)&1: ret *= p[i]
    if bin(mask).count('1')&1: ret = -ret
    return ret


n, k = map(int, input().split())
ans = n*k*(n*k+1)//2

p = get_p(n)
for i in range(1, 1<<len(p)):
    cur = f(p, i)
    m = n*k // abs(cur)
    ans += cur * m * (m+1) // 2

print(ans)
