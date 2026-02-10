import sys
input = lambda: sys.stdin.readline().rstrip()


from itertools import permutations as perm


n = int(input())
arr = list(map(int, input().split()))

ans = 0
for p in perm(range(n-2)):
    idx = [n] + list(p) + [n]
    cur = 0
    for i in range(1, n-1):
        l, r = i, i
        while idx[l] <= idx[i]: l -= 1
        while idx[r] <= idx[i]: r += 1
        cur += arr[l] * arr[r]
    ans = max(ans, cur)

print(ans)
