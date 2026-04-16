import sys
from collections import deque

input = lambda : sys.stdin.readline().rstrip()

def match(s, t):
    return sorted(s) == sorted(t)

tc = int(input())

for i in range(tc):
    n, l = map(int, input().split())
    s = list(map(lambda x: list(map(int, x)), input().split()))
    t = list(map(lambda x: list(map(int, x)), input().split()))
    ans = float('inf')

    for mask in range(1 << l):
        mask = bin(mask)[2:].zfill(l)
        for m in range(l):
            if mask[m] == '1':
                for idx in range(n):
                    s[idx][m] ^= 1
        if match(s, t):
            ans = min(ans, mask.count('1'))
        for m in range(l):
            if mask[m] == '1':
                for idx in range(n):
                    s[idx][m] ^= 1

    if ans == float('inf'):
        ans = 'NOT POSSIBLE'

    print(f'Case #{i + 1}: {ans}')
