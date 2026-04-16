from itertools import permutations as perm

n, d = map(int, input().split())
s = ''.join([str(i) for i in range(d)])
M = int(s[::-1], d)

if n >= M:
    print(-1)
    exit(0)

p = perm(s)
for i in p:
    if i[0] == '0': continue
    if int(''.join(i), d) > n:
        print(int(''.join(i), d))
        break
