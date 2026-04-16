def __pow(n, r):
    global MOD
    if r == 0:
        return 1
    ret = __pow(n, r // 2)
    ret = ret * ret % MOD
    if r & 1:
        ret = ret * n % MOD
    return ret

def inv(n):
    global MOD
    return __pow(n, MOD - 2)

def comb(n, r):
    global cache, MOD
    if r == 0: return 1
    if n == 0: return 0
    if r > n: return 0
    if 2 * r > n: return comb(n, n - r)
    if cache[n][r] == 0:
        cache[n][r] = (comb(n - 1, r) + comb(n - 1, r - 1)) % MOD
    return cache[n][r]

cache = [[0] * 1002 for _ in range(1002)]
MOD = int(1e9 + 7)

N, K = map(int, input().split())
dp = [N]

for i in range(1, K + 1):
    t = __pow(1 + N, i + 1) - 1
    s = 0
    for j in range(i):
        s += dp[j] * comb(i + 1, j)
        s %= MOD
    t -= s
    t %= MOD
    dp.append(t * inv(i + 1) % MOD)

print(dp[K])