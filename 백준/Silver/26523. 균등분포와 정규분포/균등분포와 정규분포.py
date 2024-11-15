import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass



tc = 100
for _ in range(tc):
    arr = []
    for __ in range(5000):
        arr.append(float(input()))

    s = sum(arr)
    mean = s / 5000
    var = sum(map(lambda x: x * x, arr)) / 5000 - mean ** 2

    if var < 0.07: print('B')
    else: print('A')
