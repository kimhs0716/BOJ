import sys
input = lambda: sys.stdin.readline().rstrip()


n, p = map(int, input().split())
arr = list(map(int, input().split()))
arr, c = arr[:-1], arr[-1]
coef = [0] * (p-1)
arr = arr[::-1]
for i in range(n):
    coef[i%(p-1)] += arr[i]

for i in range(p):
    s = c
    for j in range(p-1):
        s += pow(i, j+1, p) * coef[j]
    print(s % p)
