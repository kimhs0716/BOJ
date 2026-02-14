import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
arr = list(map(int, input().split()))

ans = float('inf')
for i in range(n):
    for j in range(i+1, n):
        diff = arr[j] - arr[i]
        if diff%(j-i): continue
        d = diff // (j-i)
        cur = 0
        tar = arr[i] - d*i
        for k in arr:
            cur += (tar!=k)
            tar += d
        ans = min(ans, cur)

print(ans)
