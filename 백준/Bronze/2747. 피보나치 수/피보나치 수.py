from functools import cache
@cache
def fac(n):
    if n <= 1: return n
    return fac(n - 1) + fac(n - 2)
print(fac(int(input())))