import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


while True:
    n = int(input())
    if n == 0: break
    cnt = 0
    for i in range(1, n + 1):
        if (n * n) % i != 0: continue
        j = n ** 2 // i
        if i % 2 != j % 2: continue
        c = (i + j) // 2
        b = abs(i - j) // 2
        if b > n: cnt += 1
    print(cnt)
