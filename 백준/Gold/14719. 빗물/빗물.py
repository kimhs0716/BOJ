import sys
input = lambda: sys.stdin.readline().rstrip()


m, n = map(int, input().split())
arr = list(map(int, input().split()))

left = [0] * n
right = [0] * n
for i in range(1, n):
    left[i] = max(arr[i-1], left[i-1])
for i in range(n-2, -1, -1):
    right[i] = max(arr[i+1], right[i+1])
t = [min(left[i], right[i]) for i in range(n)]
# print(t)
ans = 0
for i in range(n):
    ans += max(0, t[i]-arr[i])
print(ans)
