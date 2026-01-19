import sys
input = lambda: sys.stdin.readline().rstrip()


n, m = map(int, input().split())
res = [int(input()) for _ in range(m)]

if len(set(res))==1:
    print(1)
    if res[0]==0:
        print(1, 0, 1)
        print(1, 2, 3)
        for _ in range(n-2):
            print(1, 2, 3)
        for _ in range(m):
            print(2, 1, 2)
    else:
        for _ in range(n):
            print(1, 0, 1)
        for _ in range(m):
            print(2, 1, 2)
else:
    if n==2:
        print(-1)
    else:
        print(1)
        print(1, 0, 1)
        print(1, 0, 1)
        print(1, 2, 3)
        for _ in range(n-3):
            print(1, 0, 1)
        for i in range(m):
            if res[i]:
                print(2, 1, 2)
            else:
                print(2, 1, 3)
