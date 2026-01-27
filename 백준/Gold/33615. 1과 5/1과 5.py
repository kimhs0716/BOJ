import sys
input = lambda: sys.stdin.readline().rstrip()


for _ in range(int(input())):
    n = input()
    s = 0
    l = len(n)
    one = 0
    five = 0
    for i in n:
        s += int(i)
        if i=='1': one = 1
        if i=='5': five = 1
    if s%3==0:
        print(0, 3)
    else:
        if one==0:
            print(0, 5)
        elif five==0:
            if l&1: print(1, 11)
            else: print(0, 11)
        elif s%3==1:
            for i in range(l):
                if n[i]=='1':
                    print(i+1, 3)
                    break
        else:
            for i in range(l):
                if n[i]=='5':
                    print(i+1, 3)
                    break
