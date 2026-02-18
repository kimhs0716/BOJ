import sys
input = lambda: sys.stdin.readline().rstrip()


from decimal import Decimal


a, b, c = map(Decimal, input().split())

s = (a+b+c)/2
area = (s*(s-a)*(s-b)*(s-c)).sqrt()
R = a*b*c / (4*area)
r = area / s
d = (R*(R-2*r)).sqrt() if R-2*r>Decimal('1e-10') else Decimal(0)
k = R+r

print(area, R, r, d, k, sep='\n')
