import sys

input = sys.stdin.readline

x, y = map(int, input().split())
flag = True
if x > y:
    flag = False
    x, y = y, x
ans = []
while x:
    if flag:
        if x & 1: ans.append('B C C')
        ans.append('B B B')
        x >>= 1
    else:
        if x & 1: ans.append('A C C')
        ans.append('A A A')
        x >>= 1
print(len(ans))
print('\n'.join(ans))
print('C')

