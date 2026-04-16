from collections import deque
input = __import__('sys').stdin.readline
n = int(input())
qs = deque()
s1 = input().split()
s2 = input().split()
cnt = 0
for i in range(n):
    if s1[i] == '1': continue
    qs.append(s2[i])
    cnt += 1

res = []
m = int(input())
s3 = input().split()
for i in range(m):
    x = s3[i]
    qs.appendleft(x)
    x = qs.pop()
    res.append(x)
print(' '.join(res))
