import random

primes = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
          31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
          73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
          127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
          179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
          233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
          283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
          353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
          419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
          467, 479, 487, 491, 499, 503, 509, 521, 523, 541)

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

n = int(input())
if n == 1:
    print(1)
    exit(0)
a = n
while a % 4 == 0:
    a >>= 2
if a % 8 == 7:
    print(4)
    exit(0)
div = pollard_rho(n)
div_dict = {}
for i in div:
    if i % 4 == 3:
        if i in div_dict:
            div_dict[i] += 1
        else:
            div_dict[i] = 1

if any(map(lambda x: x & 1, div_dict.values())):
    print(3)
    exit(0)
if int(n ** 0.5) ** 2 == n:
    print(1)
else:
    print(2)
