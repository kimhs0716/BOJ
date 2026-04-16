import sys
input = lambda: sys.stdin.readline().rstrip()

def vpn(n, p):
    cnt=0
    while n%p==0:
        n //= p
        cnt += 1
        if cnt==7: break
    return cnt, n

def check(v, b, c):
    if v==7 or len(c)>=2: return True
    return v*(b**int(c))>=7

def gcd(a, b):
    if b==0: return a
    return gcd(b, a%b)

def extended_gcd(a, b):
    if b==0: return (1, 0)
    t1, t2 = extended_gcd(b, a%b)
    return (t2, t1-t2*(a//b))

def modinv(a, m):
    if gcd(a, m)!=1: return -1
    return (extended_gcd(a, m)[0]%m+m)%m

def crt(a, n, s=0):
    sz = len(a)
    if s==sz-1: return a[s]
    tmp = modinv(n[s], n[s+1])
    tmp2 = (tmp*(a[s+1]-a[s])%n[s+1]+n[s+1])%n[s+1]
    ora=a[s+1]
    tgcd=gcd(n[s], n[s+1])
    if (a[s+1]-a[s])%tgcd: return -1
    a[s+1]=a[s]+n[s]//tgcd*tmp2
    n[s+1]*=n[s]//tgcd
    ret=crt(a, n, s+1)
    n[s+1]//=n[s]//tgcd
    a[s+1]=ora
    return ret

phi2 = 2**7 - 2**6
phi5 = 5**7 - 5**6

for _ in range(int(input())):
    a, b, i, c = input().split()
    a, b, i = map(int, (a, b, i))
    if b==1:
        print(a // (10**i) % 10)
        continue
    # naive = pow(a, b**int(c), 10**7)
    v2, a2 = vpn(a, 2)
    if v2==0:
        r2 = pow(a2, pow(b, int(c), phi2), 2**7) % (2**7)
    elif check(v2, b, c): r2 = 0
    else: r2 = pow(2, v2*(b**int(c)), 2**7) * pow(a2, pow(b, int(c), phi2), 2**7) % (2**7)
    v5, a5 = vpn(a, 5)
    if v5==0:
        r5 = pow(a5, pow(b, int(c), phi5), 5**7) % (5**7)
    elif check(v5, b, c): r5 = 0
    else: r5 = pow(5, v5*(b**int(c)), 5**7) * pow(a5, pow(b, int(c), phi5), 5**7) % (5**7)
    # print(v2, a2, v5, a5)
    # print(r2, r5)
    r = [r2, r5]
    n = [2**7, 5**7]
    ans = crt(r, n)
    # print(ans, naive)
    # print(ans)
    print(ans // (10**i) % 10)
