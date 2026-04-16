s = input()
cur = s[0]
cnt = 1
for i in s[1:]:
    if cur != i:
        cnt += 1
        cur = i
print(cnt // 2)
