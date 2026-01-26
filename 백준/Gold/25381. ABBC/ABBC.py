import sys
input = lambda: sys.stdin.readline().rstrip()


from collections import deque
INF = float('inf')


s = input()
n = len(s)

a = deque()
b = deque()
c = deque()
for i in range(n):
    if s[i]=='A': a.append(i)
    elif s[i]=='B': b.append(i)
    else:
        if b: b.popleft()
        else: c.append(i)

s = []
while a or b or c:
    aa = a[0] if a else INF
    bb = b[0] if b else INF
    cc = c[0] if c else INF
    m = min((aa, bb, cc))
    if m==aa:
        s.append('A')
        a.popleft()
    if m==bb:
        s.append('B')
        b.popleft()
    if m==cc:
        s.append('C')
        c.popleft()

s = ''.join(s)

a = deque()
b = deque()
c = deque()
for i in range(len(s)):
    if s[i]=='A': a.append(i)
    elif s[i]=='B':
        if a: a.popleft()
        else: b.append(i)
    else: c.append(i)

s = []
while a or b or c:
    aa = a[0] if a else INF
    bb = b[0] if b else INF
    cc = c[0] if c else INF
    m = min((aa, bb, cc))
    if m==aa:
        s.append('A')
        a.popleft()
    if m==bb:
        s.append('B')
        b.popleft()
    if m==cc:
        s.append('C')
        c.popleft()

s = ''.join(s)

print((n-len(s))>>1)
