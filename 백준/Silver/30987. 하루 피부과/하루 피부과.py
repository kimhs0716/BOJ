x1, x2 = map(int, input().split())
a, b, c, d, e = map(int, input().split())
b -= d
c -= e

def f(x):
    return 2 * a * x ** 3 + 3 * b * x * x + 6 * c * x

print((f(x2) - f(x1)) // 6)
