import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
for _ in range(n):
    s = input()
    cnt = 0
    M = 0
    for i in s:
        if i == '[':
            cnt += 1
            M = max(M, cnt)
        else:
            cnt -= 1
    print(1 << M)
