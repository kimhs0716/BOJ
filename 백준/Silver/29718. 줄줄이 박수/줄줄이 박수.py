import sys
input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
arr = [0] * m
for _ in range(n):
    i = map(int, input().split())
    for j in range(m):
        arr[j] += next(i)

a = int(input())
M = 0
for i in range(m - a + 1):
    M = max(M, sum(arr[i: i + a]))
print(M)
