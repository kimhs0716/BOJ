n, l = map(int, input().split())
arr = list(map(int, input().split()))

ans = 0
cur = 0
for i in range(n):
    cur += arr[i]
    if 129 <= cur <= 138:
        ans += 1
    if i>=l-1: cur -= arr[i-l+1]
print(ans)
