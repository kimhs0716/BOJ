import decimal
from decimal import Decimal

decimal.getcontext().prec = 30
Pi = Decimal('3.1415926535897932384626433832795')
diff = Decimal('1e-20')


def __sin(x):
    while x < -Pi: x += 2 * Pi
    while x > Pi: x -= 2 * Pi
    fac = Decimal('1.0')
    result = Decimal('0')
    xx = Decimal('1.0')
    for i in range(1, 250):
        fac *= i
        xx *= x
        if i % 2 == 0: continue
        if i % 4 == 1:
            result += xx / fac
        else:
            result -= xx / fac
    return result


a, b, c = map(Decimal, input().split())
m, M = Decimal('-1e6'), Decimal('1e6')


def __abs(f):
    return f if f >= 0 else -f


while True:
    mid = (M + m) / 2
    f = a * mid + b * __sin(mid) - c
    # print(mid, f)
    if __abs(f) < diff:
        break
    if f < 0:
        m = mid
    else:
        M = mid
print(round(mid, 6))
