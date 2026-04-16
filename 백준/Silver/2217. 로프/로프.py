import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
M = 0
arr = [int(input()) for _ in range(n)]
arr.sort(reverse=True)
for i in range(n):
    M = max(M, arr[i] * (i + 1))
print(M)
