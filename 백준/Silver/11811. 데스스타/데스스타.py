import sys
from functools import reduce

input = sys.stdin.readline

n = int(input())
for i in range(n):
    arr = list(map(int, input().split()))
    print(reduce(lambda x, y: x | y, arr), end=' ')
