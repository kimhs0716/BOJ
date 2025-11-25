import sys
input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n = int(input())
    if n <= 14:
        print((0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88)[n], end=' ')
    else:
        print((108, 188, 200, 208, 288, 688, 888)[(n-1)%7], end='')
        print('8' * ((n-15)//7), end=' ')

    t = '1' * (n//2)
    if n&1:
        print('7'+t[1:])
    else:
        print(t)
