arr = 'i', 'pa', 'te', 'ni', 'niti', 'a', 'ali', 'nego', 'no', 'ili'
s = input().split()
ans = []
ans.append(s[0][0].upper())
for i in s[1:]:
    if i in arr: continue
    ans.append(i[0].upper())
print(''.join(ans))
