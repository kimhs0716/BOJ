from itertools import product as p
import re

s = input()
pa = re.compile('(.*[^0-9]00+)|(^00+)')
ans = []
for i in p('+-* ', repeat=len(s) - 1):
    n = s[0]
    for j in range(len(s) - 1):
        n += i[j] + s[j + 1]
    n = n.replace(' ', '')
    try:
        if eval(n) == 2000:
            ans.append(n)
    except:
        pass
for i in sorted(ans):
    if i == s or pa.match(i): continue
    print(i)
