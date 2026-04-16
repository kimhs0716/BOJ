import sys
input = lambda: sys.stdin.readline()[:-1]

for _ in '*'*int(input()):
    n = int(input())
    arr = input().split()
    flag = True
    s = set()
    for i in arr:
        a, b = i[:-2], i[-2:]
        if '-' in i: flag = False
        s.add(b)
    if flag and len(s)==1 and n!=1: print("YES")
    else: print("NO")