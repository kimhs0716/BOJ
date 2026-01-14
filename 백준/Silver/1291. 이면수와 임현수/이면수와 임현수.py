import sys
input = lambda: sys.stdin.readline()[:-1]


def get_p(n):
    if n==1: return [1]
    ret = []
    if n%2==0:
        ret.append(2)
        while n%2==0:
            n >>= 1
    i = 3
    while i*i<=n:
        if n%i==0:
            ret.append(i)
            while n%i==0:
                n //= i
        i += 2
    if n!=1:
        ret.append(n)
    return ret


def is_absolute(n):
    return n==4 or n>=6


n = int(input())
ans = 0

if is_absolute(n) and sum(map(int, str(n)))&1:
    ans |= 1

if n==2 or n==4 or len(get_p(n))%2==0:
    ans |= 2

if ans==0 or ans==3:
    ans = 3+ans//3

print(ans)
