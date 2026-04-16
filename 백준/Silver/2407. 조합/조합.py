n, m = map(int, input().split())

def C(n, r):
    res = 1
    for i in range(1, r + 1):
        res *= n - i + 1
        res //= i
    return res

print(C(n, m))
