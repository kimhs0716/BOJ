import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
idx = 0
arr = []

for i in range(n):
    x = int(input())
    t = 1
    while x % 2 == 0:
        t <<= 1
        x >>= 1
    arr.append((idx, idx + t, x))
    idx += t

idx = 0
q = int(input())
for i in range(q):
    x = int(input()) - 1
    while arr[idx][1] <= x:
        idx += 1
    print(arr[idx][2])
