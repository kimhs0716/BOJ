n = int(input())
arr = list(map(int, input().split()))
arr.sort()
m = 0
ans = -1
for i in range(n - 1):
    if (arr[i + 1] - arr[i]) // 2 > m:
        m = (arr[i + 1] - arr[i]) // 2
        ans = arr[i] + m
print(ans)