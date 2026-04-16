import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
ans = [0]*n
a=(n+2)//2
b=a-1
for i in range(n//2):
    print(a, end=' ')
    if b: print(b, end=' ')
    a += 1
    b -= 1
if n&1:
    print(n)
