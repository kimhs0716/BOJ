MOD = int(1e9 + 7)

def __pow(n, r):
    if r == 0: return 1
    ret = __pow(n, r // 2)
    ret = ret * ret % MOD
    if r & 1: ret = ret * n % MOD
    return ret

def inv(n):
    return __pow(n, MOD - 2)

n, r = map(int, input().split())
ans = 1
for i in range(r):
    # if i % 10000 == 0: print(i)
    ans = ans * (n - i) % MOD
    ans = ans * inv(i + 1) % MOD
print(ans)
