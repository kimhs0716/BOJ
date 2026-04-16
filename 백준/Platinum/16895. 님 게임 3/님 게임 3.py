n = int(input())
arr = list(map(int, input().split()))
x = 0
for i in arr:
    x ^= i

cnt = 0
for i in arr:
    if x and i >= x ^ i: cnt += 1

print(cnt)
