from collections import Counter

n, m = map(int, input().split())

s = [input() for _ in '_' * n]
arr = [Counter(map(lambda x: x[i], s)) for i in range(m)]
ans = []
cnt = 0
for i in arr:
    ans.append(min(tuple(dict(i).items()), key=lambda x: (-x[1], x[0]))[0])
    cnt += sum(map(lambda x: i[x], i)) - i[ans[-1]]
print(''.join(ans))
print(cnt)
