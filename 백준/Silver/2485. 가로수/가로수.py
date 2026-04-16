from math import gcd

n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))
g = abs(arr[0] - arr[1])
for i in range(1, n):
        g = gcd(g, abs(arr[i] - arr[i - 1]))
assert arr == sorted(arr)

print((max(arr) - min(arr)) // g - n + 1)
