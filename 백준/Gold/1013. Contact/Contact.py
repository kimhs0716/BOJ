import re
p = re.compile('(100+1+|01)+')
n = int(input())
for _ in range(n):
    if p.fullmatch(input()): print("YES")
    else: print("NO")