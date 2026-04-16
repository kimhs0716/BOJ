def factorial(k):
    fact = 1
    for i in range(1, k + 1):
        fact *= i
    return fact

def comb(n, r):
    return factorial(n) // (factorial(r) * factorial(n-r))

n, m = map(int, input().split())
x, y = map(int, input().split())

s = 0
for _ in range(m):
    a, b = map(int, input().split())
    if a != 0: s += 1

cnt = (factorial(n - s) * comb(9 - m, n - m))

ans = cnt * x + (cnt // 3) * y - y * (0 if cnt % 3 else 1)
print(ans)
