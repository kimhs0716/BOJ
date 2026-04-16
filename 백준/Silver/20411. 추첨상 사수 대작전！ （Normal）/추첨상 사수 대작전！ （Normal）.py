def __pow(n, r, mod):
    if r == 0: return 1
    ret = __pow(n, r >> 1, mod)
    ret = ret * ret % mod
    if r & 1: ret = ret * n % mod
    return ret

def __inv(n, mod):
    return __pow(n, mod - 2, mod)

m, seed, x1, x2 = map(int, input().split())
a = (x1 - x2) * __inv(seed - x1, m) % m
c = (x1 - a * seed) % m

print(a, c)
