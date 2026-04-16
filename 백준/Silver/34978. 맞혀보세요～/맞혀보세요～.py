import sys
input = lambda: sys.stdin.readline()[:-1]

n = int(input())
ok = dict()
for _ in range(n):
    ch, m, *nxt = input().split()
    ok[ch] = set(nxt)

s = input()
for i in range(len(s)-1):
    if s[i] not in ok or s[i+1] in ok[s[i]]: continue
    print("no")
    break
else:
    print("yes")
