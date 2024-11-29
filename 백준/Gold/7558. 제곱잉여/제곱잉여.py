import sys
from random import random

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


def isprime(n):
    if n < 2: return False
    if n == 2: return True
    if n % 2 == 0: return False
    i = 3
    while i * i <= n:
        if n % i == 0: return False
        i += 2
    return True

def legendre(a, p):
    # print(f'({a}, {p})')
    a %= p
    if p < 100 and False:
        for i in range(p):
            if i * i % p == a: return 1
        return -1
    if a == 1: return 1
    if a == p - 1: return (-1) ** ((p - 1) // 2)
    if a == 2: return (-1) ** ((p * p - 1) // 8)
    if a % 2 == 1 and p % a != 0 and isprime(a): return legendre(p, a) * (-1) ** ((a - 1) * (p - 1) // 4)
    i = int(a ** 0.5) + 1
    while i >= 2:
        if a % i == 0:
            return legendre(i, p) * legendre(a // i, p)
        i -= 1
    for i in range(p):
        if i * i % p == a: return 1
    return -1

tc = int(input())
for i in range(tc):
    a, p = map(int, input().split())
    print(f'Scenario #{i + 1}:')
    print(legendre(a, p))
    if i != tc - 1:
        print()
