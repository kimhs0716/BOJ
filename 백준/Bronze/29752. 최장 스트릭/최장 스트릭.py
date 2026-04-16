n = int(input())
arr = [*map(int, input().split())]
ans = 0
cur = 0

for i in range(n):
    if arr[i]:
        cur += 1
        ans = max(ans, cur)
    else:
        cur = 0
print(ans)
