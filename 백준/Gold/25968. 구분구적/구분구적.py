import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


def make_f(coefs):
    def f(x):
        xx = x * x
        ans = 0
        for coef in coefs:
            ans *= xx
            ans += coef
        return ans
    return f, (-1 if coefs[0] < 0 else 1)

def find_root(f, sign):
    m, M = 0, 33
    for _ in range(100):
        mid = (m + M) / 2
        fmid = f(mid)
        if sign * fmid < 0: m = mid
        else: M = mid
    return mid

def integral(f, a, b, steps):
    ret = 0
    dx = abs(b - a) / steps
    for i in range(steps):
        ret += f(a + (2 * i + 1) * dx / 2) * dx
    return ret

n = int(input())
coefs = list(map(float, input().split()))
k = int(input())
f, sign = make_f(coefs)

root = find_root(f, sign)

print(2 * abs(integral(f, 0, root, k // 2)))
