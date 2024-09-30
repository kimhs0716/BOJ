"""
마든 정리: https://en.wikipedia.org/wiki/Marden%27s_theorem
"""

import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


for _ in range(int(input())):
    x1, y1, x2, y2, x3, y3 = map(float, input().split())
    a, b, c = complex(x1, y1), complex(x2, y2), complex(x3, y3)

    M = (a + b) / 2
    A = a + b + c
    B = a * b + b * c + c * a

    f1 = (A + (A * A - 3 * B) ** 0.5) / 3
    f2 = (A - (A * A - 3 * B) ** 0.5) / 3

    if f1.real > f2.real: f1, f2 = f2, f1
    elif f1.imag > f2.imag: f1, f2 = f2, f1

    r = abs(M - f1) + abs(M - f2)
    print(f'{f1.real:.2f} {f1.imag:.2f} {f2.real:.2f} {f2.imag:.2f} {r:.2f}')
