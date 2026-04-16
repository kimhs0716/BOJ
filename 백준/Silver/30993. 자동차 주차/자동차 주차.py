def fac(n):
    if n == 0: return 1
    return n * fac(n - 1)

n, a, b, c = map(int, input().split())
print(fac(n) // (fac(a) * fac(b) * fac(c)))