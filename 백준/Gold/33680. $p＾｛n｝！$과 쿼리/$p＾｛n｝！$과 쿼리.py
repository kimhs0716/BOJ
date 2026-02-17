import sys
input = lambda: sys.stdin.readline().rstrip()


MOD = 10**9+7


for _ in range(int(input())):
    p, n = map(int, input().split())
    print((pow(p, n, MOD)+MOD-1) * pow(p-1, MOD-2, MOD) % MOD)
