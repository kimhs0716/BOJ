import sys
input = lambda: sys.stdin.readline().rstrip()


MOD = 10**9+7

def fac(x):
    ret = 1
    for i in range(1, x+1):
        ret = ret*i%MOD
    return ret

def inv(x):
    return pow(x, MOD-2, MOD)

n, k = map(int, input().split())
ans = fac(n)
for i in range(k):
    c = (n-i+k-1)//k
    ans = ans * inv(fac(c)) % MOD

print(ans)
