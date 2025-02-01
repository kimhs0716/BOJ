import sys

input = lambda: sys.stdin.readline().rstrip()
inf = float('inf')

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


h1, d1, t1 = map(int, input().split())
h2, d2, t2 = map(int, input().split())

time = 0
while True:
    if time % t1 == 0:
        h2 -= d1

    if time % t2 == 0:
        h1 -= d2

    if h1 <= 0:
        if h2 <= 0:
            print('draw')
        else:
            print('player two')
    elif h2 <= 0:
        print('player one')
    else:
        time += 1
        continue
    break
