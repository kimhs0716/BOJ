import sys
input = lambda: sys.stdin.readline().rstrip()


s = input()
n = len(s)
sarr = [[0] * 26]
for i in range(n):
    cur = sarr[-1][:]
    cur[ord(s[i]) - 97] += 1
    sarr.append(cur)
q = int(input())
for _ in range(q):
    ch, l, r = input().split()
    l = int(l)
    r = int(r)
    print(sarr[r + 1][ord(ch) - 97] - sarr[l][ord(ch) - 97])
