import sys
input = lambda: sys.stdin.readline().rstrip()


for _ in range(int(input())):
    n = int(input())
    if n<=1: print(1, 0)
    else: print(0, 1)
