import sys
input = lambda: sys.stdin.readline().rstrip()


n, q = map(int, input().split())
s = input()
idx = []
a, b = 0, 0
for i in range(2*n-1):
    if s[i] == '|':
        a += 1
        b = 0
    elif s[i] == '&':
        b += 1
    else:
        idx.append((a, b))
s = s.split('|')
s = [list(map(int, x.split('&'))) for x in s]
cnt = [sum(x) for x in s]
ans = sum(cnt[i]==len(s[i]) for i in range(len(cnt)))

# print(s)
# print(cnt)
# print(idx)
# print(ans)
res = ''

for q in map(int, input().split()):
    a, b = idx[q-1]
    x = s[a][b]
    if x:
        cnt[a] -= 1
        if cnt[a] == len(s[a])-1: ans -= 1
    else:
        cnt[a] += 1
        if cnt[a] == len(s[a]): ans += 1
    s[a][b] = 1-x
    res += str(int(bool(ans)))
    # print(ans)

print(res)
    

