n, k = map(int, input().split())
x = [*map(int, input().split())]

cnt = 0
idx = 0
m = x[idx]
for t in range(1, x[-1] + int(1e6)):
    if m + k == t:
        # print(t)
        cnt += 1
        while x[idx] <= t:
            idx += 1
            if idx >= n: break
        if idx >= n: break
        m = x[idx]

print(cnt)
