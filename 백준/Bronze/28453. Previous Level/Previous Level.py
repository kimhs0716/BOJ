import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())

arr = list(map(int, input().split()))
for i in arr:
    if i == 300: print(1)
    elif i >= 275: print(2)
    elif i >= 250: print(3)
    else: print(4)