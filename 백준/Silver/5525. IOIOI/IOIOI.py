import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
m = int(input())
s = input()

ans = 0
i = 0
cur = 0
while i < m:
    if s[i:i+3] == 'IOI':
        i += 2
        cur += 1
    else:
        ans += max(cur - n + 1, 0)
        cur = 0
        i += 1

print(ans)
