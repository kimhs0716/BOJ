from decimal import Decimal, getcontext

getcontext().prec = 10

c = Decimal('299792458')
v1, v2 = map(Decimal, input().split())

print((v1 + v2) / (1 + v1 * v2 / (c * c)))