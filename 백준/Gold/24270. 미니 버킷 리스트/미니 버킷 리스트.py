import sys
input = lambda: sys.stdin.readline().rstrip()


MOD = 10**9+7


def fac(n):
    ret = 1
    for i in range(1, n+1):
        ret = ret*i%MOD
    return ret


n, k = map(int, input().split())
arr = map(int, input().split())
s = sum(arr)

ans = 1
for i in range(n):
    ans = ans*(i+k-s+1)%MOD

print(ans)
