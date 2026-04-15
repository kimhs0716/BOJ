import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
if n<=4: print(4)
else:
    x, y = 1, 2
    while x*y < n:
        if x==y: y += 1
        else: x += 1
    print(2*(x+y-2))
