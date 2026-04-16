import sys
input = lambda: sys.stdin.readline().rstrip()


R, G, B = map(int, input().split())

if max((R, G, B)) == 0:
    print(0, 0, 0, 1)
else:
    R /= 255
    G /= 255
    B /= 255
    K = 1 - max((R, G, B))
    for x in (R, G, B):
        print((1-x-K)/(1-K), end=' ')
    print(K)
