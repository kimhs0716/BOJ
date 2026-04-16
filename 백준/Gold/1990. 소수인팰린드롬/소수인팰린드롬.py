def make_pal(n, f = False):
    n = str(n)
    if f == True:
        n = n + n[::-1]
    else:
        n = n + n[-2::-1]
    return int(n)

arr = [1] * 10001
arr[0] = arr[1] = 0
i = 1
while i * i <= 10000:
    while arr[i] == 0: i += 1
    j = 2
    while i * j <= 10000:
        arr[i * j] = 0
        j += 1
    i += 1

primes = []
for i in range(10001):
    if arr[i]: primes.append(i)

def isprime(n):
    if n in primes: return True
    for i in primes:
        if i * i > n: return True
        if n % i == 0: return False
    return True

n, m = map(int, input().split())

taken = len(str(n))
takem = len(str(m))

for i in range(taken, takem + 1):
    if i % 2 == 0:
        for j in range(10 ** (i // 2 - 1), 10 ** (i // 2)):
            pal = make_pal(j, 1)
            if pal < n: continue
            if pal > m: break
            if isprime(pal): print(pal)
            
    else:
        for j in range(10 ** ((i + 1) // 2 - 1), 10 ** ((i + 1) // 2)):
            pal = make_pal(j)
            if pal < n: continue
            if make_pal(j) > m: break
            if isprime(pal): print(pal)
            
print(-1)
