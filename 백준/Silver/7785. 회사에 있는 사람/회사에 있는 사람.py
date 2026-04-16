import sys
input = sys.stdin.readline
s = set()
for _ in range(int(input())):
    a, b = input().split()
    if b == 'enter':
        s |= set((a, ))
    else:
        s -= set((a, ))
for i in sorted(s, reverse=True):
    print(i)
