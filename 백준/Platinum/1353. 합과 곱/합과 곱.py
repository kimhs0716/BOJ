from decimal import *
e = Decimal('2.718281828459045')

def __pow(n, r):
    if r == 0:
        return Decimal('1')
    ret = __pow(n, r // 2)
    if ret > 1e100:
        ret = Decimal('1e100')
    ret *= ret
    if r & 1:
        ret *= n
    return ret

s, p = map(Decimal, input().split())
if s == p:
    print(1)
    exit(0)

a = int(s / e)
if a == 0: a += 1
if __pow(s / a, a) < p and __pow(s / (a + 1), a + 1) <= p:
    print(-1)
    exit(0)
    
for i in range(2, int(s / e) + 100):
    if __pow(s / i, i) >= p:      
        found = True
        print(i)
        break
else:
    assert False
