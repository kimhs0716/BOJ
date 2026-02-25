import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
cur = 1
while True:
    l = len(str(cur))
    if n <= l:
        print(str(cur)[n-1])
        break
    n -= l
    cur += 1
