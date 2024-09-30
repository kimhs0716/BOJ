"""
풀이 과정

반지름이 R인 원 내부의 임의의 점 (x, y)를 고를 때 x-좌표의 값이 x일 확률 밀도 함수
f_X(x) = 2 / (pi * R^2) * sqrt(R^2 - x^2)

E(X^2) = E(Y^2)) = integral from x=-R to R (x^2 * f_X(x)) dx = R^2 / 4
반지름이 r인 원에서 거리를 확률변수 R라고 하면, E(R^2) = r^2 / 2

반지름이 r인 원에서 위치 벡터를 확률변수 X라 하면
구하는 값 = E((X1 + X2 + ... + Xn)^2)
곱셈 공식 사용하면
E(X1^2 + ... + Xn^2 + 2(X1X2 + X1X3 + ... + X_(n-1)Xn))
그런데 E(X) = 0이므로
구하는 값 = E(X1^2 + ... Xn^2) = (r1^2 + ... + rn^2) / 2
"""


import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

n = int(input())
arr = map(int, input().split())
print(f'{sum(map(lambda x: x * x, arr)) / 2:.10f}')
