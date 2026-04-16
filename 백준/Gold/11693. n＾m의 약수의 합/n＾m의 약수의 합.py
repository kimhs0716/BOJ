mod = int(1e9+7)

def powmod(n, r, m):
    if r == 0: return 1
    ret = powmod(n, r // 2, m)
    ret = ret * ret % m
    if r & 1: ret = ret * n % m
    return ret

isprime = [1] * 100001
isprime[0] = isprime[1] = 0
isprime[2] = isprime[3] = 1
i = 2
while i * i <= 100000:
    j = 2
    while i * j <= 100000:
        isprime[i * j] = 0
        j += 1
    i += 1
    while isprime[i] == 0: i += 1

primes = []
for i in range(100001):
    if isprime[i]: primes.append(i)

n, m = map(int, input().split())
divs = {}
for p in primes:
    if n == 1: break
    if p * p > n:
        divs[n] = m
        break
    if n % p == 0:
        divs[p] = 0
        while n % p == 0:
            divs[p] += m
            n //= p
    
def inv(n):
    return powmod(n, mod - 2, mod)

ans = 1
for p, r in divs.items():
    ans = ans * (powmod(p, r + 1, mod) - 1) % mod
    ans = ans * inv(p - 1) % mod

print(ans)
