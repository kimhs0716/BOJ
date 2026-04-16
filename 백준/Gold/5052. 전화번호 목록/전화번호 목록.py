import sys
input = lambda: sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    n = int(input()) 

    tree = dict()
    cur = tree
    flag = True

    arr = []
    for __ in range(n):
        arr.append(input())
    arr.sort()
    
    for a in arr:
        cur = tree
        for idx, i in enumerate(a):
            if i in cur:
                if cur[i][0] == True:
                    flag = False
                    break
            else:
                cur[i] = [False, dict()]
            if idx == len(a) - 1:
                cur[i][0] = True
            cur = cur[i][1]
            if flag == False: break
    print('NYOE S'[flag::2])