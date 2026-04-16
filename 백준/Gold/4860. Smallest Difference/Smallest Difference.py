import sys
input = lambda: sys.stdin.readline().rstrip()

from itertools import permutations

for _ in range(int(input())):
    ans = 1e100
    arr = input().split()
    arr.sort()

    for p in permutations(arr):
        l = list(p)
        i = len(arr)//2
        a = l[:i]
        b = l[i:]
        if len(a)!=1 and a[0]=='0': continue
        if len(b)!=1 and b[0]=='0': continue
        # print(a, b)
        ans = min(ans, abs(int(''.join(a))-int(''.join(b))))

    print(ans)
