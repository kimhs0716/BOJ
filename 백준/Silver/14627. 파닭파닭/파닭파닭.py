import sys
input = lambda: sys.stdin.readline().rstrip()

def pred(l):
    s = 0
    for i in arr:
        s += i // l
    return s

k, n = map(int, input().split())
arr = [ int(input()) for _ in range(k) ]
s = sum(arr)
m, M = 1, int(1e10)

while True:
    mid = (m + M) // 2
    p = pred(mid)
    if p < n: M = mid
    else: m = mid
    # print(m, mid, M)
    if m + 1 == M:
        break

print(s - n * max((m, M), key=pred))
