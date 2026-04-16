import sys
input = lambda: sys.stdin.readline()[:-1]

from math import ceil
for _ in range(int(input())):
    n = int(input())
    x = int(n**0.5)
    if x*x>=n: print(x*4)
    elif x*(x+1)>=n: print(x*4+2)
    else: print(x*4+4)