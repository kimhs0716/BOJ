import sys
input = lambda: sys.stdin.readline().rstrip()


MOD = 998244353

for _ in range(int(input())):
    n, m, M = map(int, input().split())
    r = M-m+1
    if r==1:
        print(1)
    else:
        ans = pow(r, n, MOD)
        ans -= 2*pow(r-1, n, MOD)
        ans += pow(r-2, n, MOD)
        print(ans % MOD)

