import sys
input = lambda: sys.stdin.readline()[:-1]

n, x = map(int, input().split())
m = float('inf')
arr = list(map(int, input().split()))
for i in range(n - 1):
    m = min(m, arr[i] + arr[i + 1])
print(m * x)
