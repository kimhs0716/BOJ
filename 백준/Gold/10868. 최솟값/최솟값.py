import sys
input = lambda: sys.stdin.readline().rstrip()


def ctz(x):
    return (x & -x).bit_length()


def msb(x):
    x |= x>>1
    x |= x>>2
    x |= x>>4
    x |= x>>8
    x += 1
    return x>>1


INF = 10**18

n, q = map(int, input().split())
arr = [int(input()) for _ in range(n)]
k = ctz(msb(n))

rmq = [[INF] * n for _ in range(k)]
for i in range(n):
    rmq[0][i] = arr[i]
for i in range(1, k):
    for j in range(n-(1<<(i-1))):
        rmq[i][j] = min(rmq[i-1][j], rmq[i-1][j+(1<<(i-1))])

for _ in range(q):
    a, b = map(int, input().split())
    l = ctz(msb(b-a+1)) - 1
    # print(l, a-1, b-(1<<l))
    print(min(rmq[l][a-1], rmq[l][b-(1<<l)]))
    
