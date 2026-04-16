import random
import math

primes = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71)

def g(x, c, num):
    return (x * x + c) % num

def gcd(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a

def __isprime(num):
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

def pollard_rho(num):
    if __isprime(num):
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
        return pollard_rho(num // d) + pollard_rho(d)

def analyze(num, idx):
    print("Fib(%d) = %d, lg " % (idx, num), end="")
    if num == 0:
        print("does not exist")
    else:
        print("is %.6f" % math.log(num, 2))
    if num < 2:
        print("No prime factors")
    else:
        print("Prime factors:", end=" ")
        print(" ".join(map(str, sorted(pollard_rho(num)))))

while True:
    try:
        a, b = input().replace("0x", "").split()
    except:
        break
    a = int(a, 16)
    b = int(b, 16)
    if a >= b:
        break
    print("Range %d to %d:" % (a, b))
    n1, n2 = 0, 1
    idx = 0
    exist = False
    while n1 < a:
        n1, n2 = n2, n1 + n2
        idx += 1
    while n1 <= b:
        analyze(n1, idx)
        n1, n2 = n2, n1 + n2
        exist = True
        idx += 1
    if exist == False:
        print("No Fibonacci numbers in the range")
    print()
