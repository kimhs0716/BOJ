import sys
input = lambda: sys.stdin.readline().rstrip()



def factorize(n):
    res = []
    i = 1
    while i*i<n:
        if n%i==0:
            res.append(i)
            res.append(n//i)
        i += 1
    if i*i==n: res.append(i)
    return sorted(res)

x = int(input())
f = factorize(x+1)
print(*f[:-1])
        
    
