import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


size = 10 ** 6
isprime = [True] * (size + 1)
isprime[0] = False
isprime[1] = False

i = 2
while i <= size:
    j = 2
    while i * j <= size:
        isprime[i * j] = False
        j += 1
    i += 1
    while i <= size and isprime[i] == 0: i += 1

for _ in range(int(input())):
    n = int(input())
    cnt = 0
    for i in range(2, n // 2 + 1):
        if not isprime[i]: continue
        if isprime[n - i]: cnt += 1
    print(cnt)
