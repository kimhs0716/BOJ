import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import Counter


s = input()
n = len(s)
sarr = [Counter()]
for i in range(n):
    sarr.append(sarr[-1] + Counter({s[i]: 1}))
q = int(input())
for _ in range(q):
    ch, l, r = input().split()
    l = int(l)
    r = int(r)
    print((sarr[r + 1] - sarr[l])[ch])
