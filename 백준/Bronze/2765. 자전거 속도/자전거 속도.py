import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


pi = 3.141592653589793
i = 1
while True:
    a, b, c = map(float, input().split())
    if b == 0: break
    dis = a * b * pi / 63360
    v = dis * 3600 / c
    print(f"Trip #{i}: {dis:.2f} {v:.2f}")
    i += 1
