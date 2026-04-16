import sys
input = lambda: sys.stdin.readline().rstrip()

# sys.stdin = open('boj.in', 'r', encoding='utf-8')

def solve(n):
    if n == 0: return ''

    if n % 3 == 0: return solve(n // 3) + '0'
    elif n % 3 == 1: return solve(n // 3) + '1'
    else: return solve(n // 3 + 1) + 'T'

n = int(input())
if n == 0: print(0)
else: print(solve(n))
