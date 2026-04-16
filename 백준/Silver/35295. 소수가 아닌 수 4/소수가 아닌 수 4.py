import sys
input = lambda: sys.stdin.readline().rstrip()


from math import lcm


def isprime(n):
    if n<2: return False
    if n%2==0: return n==2
    i = 3
    while i*i <= n:
        if n%i==0: return False
        i += 2
    return True


n = int(input())
arr = list(map(int, input().split()))

l = 1
for i in arr:
    l = lcm(l, i)

if isprime(l):
    print("NO")
else:
    print("YES")
    print(n)
    print(*arr)

