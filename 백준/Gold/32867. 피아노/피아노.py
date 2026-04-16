import sys
input = lambda: sys.stdin.readline().rstrip()


ans = 0
n, k = map(int, input().split())
arr = list(map(int, input().split()))

i = 0
while i < n:
    m, M = arr[i], arr[i]
    while True:
        if i == n - 1: break
        if arr[i + 1] + k <= M: break
        elif m + k <= arr[i + 1]: break
        i += 1
        m = min(m, arr[i])
        M = max(M, arr[i])
    # print(i, m, M)
    ans += 1
    if i == n - 1: break
    i += 1

print(ans - 1)
