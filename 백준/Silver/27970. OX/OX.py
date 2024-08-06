import sys
input = lambda: sys.stdin.readline()[:-1]

mod = int(1e9+7)
s = input()
ans = 0
for i in range(len(s)):
    if s[i] == 'O':
        ans += (1 << i)
        ans %= mod
print(ans)
