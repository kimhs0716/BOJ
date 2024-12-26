import sys

input = lambda: sys.stdin.readline().rstrip()
inf = float('inf')

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


from itertools import product
n, _ = map(int, input().split())
i = len(str(n))
k = sorted(input().split(), reverse=True)

while True:
    p = product(k, repeat=i)
    for pp in p:
        if int(''.join(pp)) <= n:
            print(''.join(pp))
            exit(0)
    i -= 1
