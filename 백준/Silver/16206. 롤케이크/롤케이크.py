n, m = map(int, input().split())
s = 0
arr = list(map(int, input().split()))
arr.sort(key=lambda x: (x % 10, x))
for i in range(n):
    while arr[i] > 10 and m > 0:
        arr[i] -= 10
        m -= 1
        s += 1
    if arr[i] == 10:
        s += 1
print(s)
        