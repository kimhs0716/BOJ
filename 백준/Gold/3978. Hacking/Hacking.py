import sys
input = lambda: sys.stdin.readline()[:-1]


from itertools import product as p
from string import ascii_lowercase


for _ in range(int(input())):
    n, m, k = map(int, input().split())
    s = set()
    t = input()
    for i in range(n-m+1):
        s.add(t[i:i+m])
    for i in p(ascii_lowercase[:k], repeat=m):
        i = ''.join(i)
        if i in s: continue
        print(i)
        break
