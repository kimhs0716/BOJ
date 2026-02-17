import sys
input = lambda: sys.stdin.readline().rstrip()


s = input()
t = input()

l, r = 0, 0
ans = 0
while r<=len(s):
    if s[l:r] in t:
        ans = max(ans, r-l)
        r += 1
    else:
        l += 1

print(ans)
