import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
cur = 1
l = 1
nxt = 10
while True:
    if n <= l:
        print(str(cur)[n-1])
        break
    n -= l
    cur += 1
    if cur == nxt:
        l += 1
        nxt *= 10
