import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n = int(input())

if n <= 3:
    print(-1)
elif n % 2 == 0:
    k = n // 2 - 1
    i = 2
    for _ in range(k):
        print(i)
        i += 1
    i += 1
    for _ in range(k):
        print(i)
        i += 1
    print(1, k + 2, sep='\n')
else:
    for i in range(2, n - 1):
        print(i)
    print(1, n, n - 1, sep='\n')
