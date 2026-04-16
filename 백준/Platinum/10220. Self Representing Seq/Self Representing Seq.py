import sys
input = lambda: sys.stdin.readline()[:-1]

for _ in range(int(input())):
    n = int(input())
    if n in (1, 2, 3, 6):
        print(0)
    elif n == 4:
        print(2)
    else:
        print(1)
