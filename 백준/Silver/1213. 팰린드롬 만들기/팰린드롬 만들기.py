import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import Counter

s = input()
c = dict(Counter(s))

odds = 0
for key, value in c.items():
    if value & 1: odds += 1

if odds == 0:
    sp = ''
if odds <= 1:
    ans = ''
    for i in sorted(c.keys()):
        if c[i] & 1:
            sp = i
        ans += i * (c[i] // 2)
    print(ans + sp + ans[::-1])
else:
    print("I'm Sorry Hansoo")
