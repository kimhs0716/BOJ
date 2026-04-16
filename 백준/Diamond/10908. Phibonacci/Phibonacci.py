mod = 1000000007
mod2 = mod * mod

F0 = [0, 1]
mat = [[0, 1], [1, 1]]

def mul(a, b, mod):
    arr = [[0, 0], [0, 0]]
    arr[0][0] = ((a[0][0] * b[0][0]) % mod + (a[0][1] * b[1][0]) % mod) % mod
    arr[0][1] = ((a[0][0] * b[0][1]) % mod + (a[0][1] * b[1][1]) % mod) % mod
    arr[1][0] = ((a[1][0] * b[0][0]) % mod + (a[1][1] * b[1][0]) % mod) % mod
    arr[1][1] = ((a[1][0] * b[0][1]) % mod + (a[1][1] * b[1][1]) % mod) % mod
    return arr

def mat_pow(a, n, mod):
    if n == 1: return a
    res = mat_pow(a, n // 2, mod)
    res = mul(res, res, mod)
    if n & 1:
        res = mul(mat, res, mod)
    return res

def fib(n, mod):
    if n == 0: return 0
    return mat_pow(mat, n, mod)[0][1]

def __pow(a, n, mod):
    if n == 0: return 1
    res = __pow(a, n // 2, mod)
    res = res * res % mod
    if n & 1:
        res = res * a % mod
    return res

def __inv(a, mod):
    return __pow(a, mod - 2, mod)

n, k = map(int, input().split())

if n == 0:
    print(0, 1)
    exit(0)

a = fib(n * k, mod2); b = fib(k, mod2)
if b % mod != 0:
    a %= mod; b %= mod
else:
    a //= mod; b //= mod
A = a * __inv(b, mod) % mod
B = fib(n * k - 1, mod) - A * fib(k - 1, mod)
B %= mod

print(A, B)
