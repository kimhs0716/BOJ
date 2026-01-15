import sys
input = lambda: sys.stdin.readline()[:-1]


def count(diff, dist):
    cur = 0
    ret = 1
    for i in range(len(diff)):
        cur += diff[i]
        if cur >= dist:
            cur = 0
            ret += 1
    return ret


n, c = map(int, input().split())
arr = [int(input()) for _ in range(n)]
arr.sort()
diff = [arr[i+1]-arr[i] for i in range(n-1)]

lo=1
hi=10**10
while lo+1<hi:
    m = (lo+hi)>>1
    k = count(diff, m)
    if k < c: hi = m
    else: lo = m

print(lo)
