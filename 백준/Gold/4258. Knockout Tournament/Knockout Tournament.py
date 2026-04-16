import sys
input = lambda: sys.stdin.readline().rstrip()


while True:
    n = int(input())
    if n==0: break
    res = map(int, input().split())
    _, *q = map(lambda x: int(x)-1, input().split())

    tree = [0] * (1<<n) + [i for i in range(1<<n)]
    for i in range(n-1, -1, -1):
        for j in range(1<<i):
            w = next(res)-1
            tree[(1<<i)+j] = w

    hi = [0] * (1<<n)
    lo = [0] * (1<<n)
    hi[tree[1]] = 1
    lo[tree[1]] = 1
    d = 1<<n
    for i in range(2, 1<<(n+1)):
        if i.bit_count()==1:
            d >>= 1
        x = tree[i]
        p = tree[i>>1]
        if x!=p:
            hi[x] = hi[p]+1
            lo[x] = (1<<n)-d+1
        # print(d)

    for x in q:
        print(f"Player {x+1} can be ranked as high as {hi[x]} or as low as {lo[x]}.")
    print()
