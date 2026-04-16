cnt = 0
x, y = map(int, input().split())
l = len(str(x))
for i in range(x, y + 1):
    s = set()
    for j in range(1, l):
        k = i // 10 ** j + i % 10 ** j * (10 ** (l - j))
        if x <= k <= y and i < k and k not in s:
            cnt += 1
            s.add(k)
print(cnt)