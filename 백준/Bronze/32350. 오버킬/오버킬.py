n, d, p = map(int, input().split())
arr = list(map(int, input().split()))
t = 0
idx = 0
while idx < n:
    t += 1
    arr[idx] -= d
    if arr[idx] <= 0:
        idx += 1
        if idx == n: break
        arr[idx] -= -p * arr[idx - 1] // 100
        if arr[idx] <= 0: idx += 1
    # print(t, idx, arr)
print(t)
