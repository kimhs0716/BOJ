import sys
from collections import Counter

input = sys.stdin.readline


def _pow(n, m, mod):
    if m == 0: return 1
    ret = _pow(n, m >> 1, mod)
    ret = (ret * ret) % mod
    if m & 1: ret = (ret * n) % mod
    return ret


def isprime(n):
    if n < 10000:
        if n < 2: return False
        if n == 2: return True
        if n % 2 == 0: return False
        i = 3
        while i * i <= n:
            if n % i == 0: return False
            i += 2
        return True
    else:  # 밀러 라빈 소수 판별법
        primes = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47)
        s = 0
        d = n - 1
        while d & 1 == 0:
            d >>= 1
            s += 1
        flag = True
        for p in primes:
            if _pow(p, d, n) == 1:
                continue
            for r in range(s):
                if _pow(p, d * (1 << r), n) == n - 1:
                    break
            else:
                flag = False
                break
        return flag


def pollard_rho(num):
    import random
    from math import gcd
    if isprime(num):
        return [num]
    if num == 4:
        return [2, 2]
    while 1:
        c = random.randint(1, 9)

        def g(x):
            return (x * x + c) % num

        x = random.randint(1, 9)
        y = x
        d = 1
        while d == 1:
            x = g(x, )
            y = g(g(y))
            d = gcd(abs(x - y), num)
        if d == num:
            continue
        return pollard_rho(num // d) + pollard_rho(d)


n = int(input())
inp = map(int, input().split())
divs = []
for i in inp:
    divs.extend(pollard_rho(i))
arr = Counter(divs).most_common()

k = arr[0][1]
ans = 0
for i, j in arr:
    if j == k:
        ans += 1
    else:
        break
print(k)
print((1 << ans) - 1)
