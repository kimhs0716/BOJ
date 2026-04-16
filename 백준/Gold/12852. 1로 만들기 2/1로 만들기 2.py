cache = {}
cache[1] = [0, []]

n = int(input())

for i in range(2, n + 1):
    idx = i - 1
    m = cache[idx][0]

    if i % 2 == 0 and cache[i // 2][0] < m:
        idx = i // 2
        m = cache[idx][0]
    if i % 3 == 0 and cache[i // 3][0] < m:
        idx = i // 3
        m = cache[idx][0]

    cache[i] = [m + 1, [idx] + cache[idx][1]]

print(cache[n][0])
print(" ".join(map(str, [n] + cache[n][1])))
