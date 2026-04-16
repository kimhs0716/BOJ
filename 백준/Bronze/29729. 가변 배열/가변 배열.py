import sys
input = lambda: sys.stdin.readline().rstrip()

s, n, m = map(int, input().split())
u = 0
for i in range(n + m):
    if input() == '1':
        u += 1
        if u > s:
            s <<= 1
    else:
        u -= 1
print(s)
