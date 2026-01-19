import sys
input = lambda: sys.stdin.readline().rstrip()


for _ in range(int(input())):
    k, c, p = map(int, input().split())
    if c+p>=2 or (k==1 and c==1):
        print('Y')
    else:
        print('N')
