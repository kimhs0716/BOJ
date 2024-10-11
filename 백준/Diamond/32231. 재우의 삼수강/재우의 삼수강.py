# 오일러 방정식 (벨트라미 항등식)을 사용하여 시간을 최소화하는 경로 y(x)를 구함
# 치환 적분을 적절히 활용하는 것이 중요

import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


from math import log, sqrt
from decimal import Decimal

tc = int(input())
for _ in range(tc):
    x1, y1, x2, y2 = map(Decimal, input().split())
    if x1 == x2:
        print(abs(log(y1 / y2)))
    else:
        B = (x1 * x1 + y1 * y1 - (x2 * x2 + y2 * y2)) / (2 * (x1 - x2))
        A = ((x1 - B) ** 2 + y1 ** 2).sqrt()

        T = (((x2 - B + A) * y1) / ((x1 - B + A) * y2)).ln()
        print(abs(T))
