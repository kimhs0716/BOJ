import sys
input = lambda: sys.stdin.readline()[:-1]

n = int(input())
arr = [*map(int, input().split())]

ans = [[] for _ in range(n)]
for i in range(1, 1<<n):
    for j in range(n):
        if (i>>j)&1:
            ans[n-j-1].append(arr[i-1])
            break
for i in ans:
    print(*i)