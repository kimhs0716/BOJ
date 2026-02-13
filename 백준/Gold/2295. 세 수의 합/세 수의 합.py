import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
arr = [int(input()) for _ in range(n)]

s = set(i+j for i in arr for j in arr)
ans = 0
for i in arr:
    for j in arr:
        if i-j in s:
            ans = max(i, ans)

print(ans)
