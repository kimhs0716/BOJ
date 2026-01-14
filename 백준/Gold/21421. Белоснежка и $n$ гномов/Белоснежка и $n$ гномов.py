import sys
input = lambda: sys.stdin.readline()[:-1]


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
arr = [[a[i], b[i], i+1] for i in range(n)]


ans = []
arr.sort(key=lambda x: (-(x[0]+x[1]), x[0]))

t = 0
m = float('inf')
for i in range(n):
    t += arr[i][0]
    if t >= m:
        print(-1)
        break
    m = min(m, t+arr[i][1])
    ans.append(arr[i][2])
else:
    print(*ans)
