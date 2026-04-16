n = int(input())
s = set(input() for _ in range(n))
cnt = dict()
for i in s:
    cnt[i] = 0
for i in s:
    for j in s:
        if i.startswith(j):
            cnt[j] += 1
s = sorted(s, key=cnt.get)
ans = []
for i in s:
    for j in ans:
        if j.startswith(i): break
    else: ans.append(i)
print(len(ans))