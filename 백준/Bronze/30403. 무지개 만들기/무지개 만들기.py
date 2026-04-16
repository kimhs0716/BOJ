from collections import Counter
input()
s = Counter(input())
r = Counter('roygbiv')
R = Counter('ROYGBIV')

if s >= r:
    if s >= R: print('YeS')
    else: print('yes')
elif s >= R: print('YES')
else: print('NO!')
