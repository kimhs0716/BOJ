import sys
input = lambda: sys.stdin.readline().rstrip()


import random


def digit(n):
    return sum(map(int, str(n)))

def solve(n):
    l = 10**18 // n
    while True:
        t = random.randint(1, l) * n
        if digit(t) & 1:
            return t
        

for _ in range(int(input())):
    print(solve(int(input())))
        
