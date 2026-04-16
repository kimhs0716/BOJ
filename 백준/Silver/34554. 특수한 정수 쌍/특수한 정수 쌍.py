import sys
input = lambda: sys.stdin.readline().rstrip()

def isprime(n):
    if n<2: return False
    if n==2: return True
    if n%2==0: return False
    i=3
    while i*i<=n:
        if n%i==0: return False
        i += 2
    return True

tc = int(input())
for _ in range(tc):
    n = int(input())
    if isprime(n+1):
        print(1)
        print(1, n+1)
    else: print(0)
