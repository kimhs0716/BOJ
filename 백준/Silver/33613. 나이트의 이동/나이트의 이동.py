import sys
input = lambda: sys.stdin.readline()[:-1]


n = int(input())
r, c = map(int, input().split())

if n == 3:
    if r == 2 and c == 2:
        print(1)
    else:
        print(4)
elif n % 2 == 0:
    print(n * n // 2)
else:
    print(n * n // 2 + (r + c + 1) % 2)
