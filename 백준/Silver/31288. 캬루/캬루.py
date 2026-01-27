import sys
input = lambda: sys.stdin.readline().rstrip()


for _ in range(int(input())):
    n, p = input().split()
    n = int(n)
    p = list(p)
    if n==1:
        print(9, 3)
        continue
    s = 0
    for i in p:
        s += int(i)
    s %= 3
    for i in range(n):
        c = int(p[i])
        t = (c-s+3)%3
        while t==0 or t==c:
            t += 3
        p[i] = str(t)
        print(''.join(p), 3)
        p[i] = str(c)
    
