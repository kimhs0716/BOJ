import sys

input = lambda: sys.stdin.readline().rstrip()
inf = float('inf')

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


a, b, c = map(int, input().split())

for i in range(1, 11):
    arr = []
    for j in range(1, 11):
        if a * i + b * j == c: arr.append(j)

    if arr: print(*arr)
    else: print(0)
