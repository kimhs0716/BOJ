def isprime(n):
    if n < 2: return False
    if n == 2: return True
    if n == 4: return False
    i = 3
    while i * i <= n:
        if n % i == 0: return False
        i += 2
    return True

def solve(n, p = 0):
    if n == 0: return [0, 0, 0, 0]
    if n == 1: return [0, 0, 0, 1]
    if int(n ** 0.5) ** 2 == n and False:
        return [0, 0, 0, int(n ** 0.5)]
    if isprime(n) or p:
        if n > 100000 and not p:
            raise RangeError
        for i in range(int(n ** 0.5) + 1):
            for j in range(int((n - i) ** 0.5) + 1):
                if i**2 + j**2 > n: continue
                for k in range(int((n - i - j) ** 0.5) + 1):
                    h2 = (n - i**2 - j**2 - k**2)
                    if h2 < 0: continue
                    h = int(h2 ** 0.5)
                    if h * h != h2: continue
                    if i**2 + j**2 + k**2 + h**2 == n:
                        return [i, j, k, h]
    d = 2
    while n % d:
        d += 1
    #print(d, n // d)
    s1 = solve(d)
    s2 = solve(n // d)
    s = [
            abs(s1[0] * s2[0] - s1[1] * s2[1] - s1[2] * s2[2] - s1[3] * s2[3]),
            abs(s1[0] * s2[1] + s1[1] * s2[0] + s1[2] * s2[3] - s1[3] * s2[2]),
            abs(s1[0] * s2[2] - s1[1] * s2[3] + s1[2] * s2[0] + s1[3] * s2[1]),
            abs(s1[0] * s2[3] + s1[1] * s2[2] - s1[2] * s2[1] + s1[3] * s2[0])
        ]
    return s

print(*solve(int(input())))
