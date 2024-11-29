import sys
from random import random

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


x, y = map(int, input().split())
print(2)
z = (y - 1) * x
print(z)
z = (x - 1) * y
print(-z)
