mod = int(1e9) + 7
n, m = map(int, input().split())
print((pow(m, n, mod) - pow(m - 1, n, mod)) % mod)
