import random

def pf(num):
    
    def gcd(a, b):
        while b != 0:
            r = a % b
            a = b
            b = r
        return a
    
    def g(x, c, num):
        return (x * x + c) % num
    
    if isprime(num):
        return [num]
    if num == 4:
        return [2, 2]
    while 1:
        c = random.randint(1, 9)
        x = random.randint(1, 9)
        y = x
        d = 1
        while d == 1:
            x = g(x, c, num)
            y = g(g(y, c, num), c, num)
            d = gcd(abs(x - y), num)
        if d == num:
            continue
        return pf(num // d) + pf(d)

def isprime(num):
    primes = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71)

    def gcd(a, b):
        while b != 0:
            r = a % b
            a = b
            b = r
        return a
    
    if num == 1:
        return False
    d = num - 1
    s = 0
    while d % 2 == 0:
        d //= 2
        s += 1
    for a in primes:
        if a >= num:
            break
        passed = False
        if pow(a, d, num) == 1:
            passed = True
            continue
        for r in range(s):
            if pow(a, pow(2, r) * d, num) == num - 1:
                passed = True
                continue
        if passed == False:
            return False
    return True

k = int(input())
for i in range(1, k + 1, 2):
    if not isprime(i): continue
    M = (1 << i) - 1
    if not isprime(M):
        f = sorted(pf(M))
        print(" * ".join(map(str, f)) + " = "\
              + str(M) + " = ( 2 ^ " + str(i) + " ) - 1")
