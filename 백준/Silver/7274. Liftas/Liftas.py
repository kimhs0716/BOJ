import sys

input = lambda : sys.stdin.readline().rstrip()

n, k = map(int, input().split())
arr = [int(input()) for i in range(n)]
arr.sort()
print(sum(arr[:n-k]))
