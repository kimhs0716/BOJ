import sys
input = lambda: sys.stdin.readline().rstrip()



def isprime(n):
    if n<2: return False
    if n==2: return True
    if n%2==0: return False
    i = 3
    while i*i <= n:
        if n%i == 0: return False
        i += 2
    return True


def issquare(n):
    if n<0: return False
    x = int(n**0.5)
    return x*x == n


def P2(arr):
    n = len(arr)
    ret = 0
    for i in range(n):
        if isprime(i) and issquare(arr[i]):
            ret += arr[i]
    return ret