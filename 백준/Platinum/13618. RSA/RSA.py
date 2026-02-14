import sys
input = lambda: sys.stdin.readline().rstrip()


def get_pq(n):
    i = 3
    while True:
        if n%i == 0:
            return i, n//i
        i += 2


def ext_gcd(a, b):
    """return (x, y) s.t. ax+by=g"""
    if b==0: return 1, 0
    p, q = ext_gcd(b, a%b)
    return q, p-q*(a//b)


n, e, c = map(int, input().split())
p, q = get_pq(n)
phi = (p-1) * (q-1)
x, y = ext_gcd(e, phi)
g = e*x + phi*y
if g==1: d = x%phi
else: d = (-x)%phi
print(pow(c, d, n))
    
