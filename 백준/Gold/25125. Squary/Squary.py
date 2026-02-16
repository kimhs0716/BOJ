import sys
input = lambda: sys.stdin.readline().rstrip()


import random


for tc in range(int(input())):
    print(f"Case #{tc+1}: ", end='')
    
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    s = sum(arr)
    s2 = sum(i*i for i in arr)

    if s*s == s2:
        print(0)
        continue

    if s==0:
        print("IMPOSSIBLE")
        continue

    if (s2-s*s) % (2*s) == 0:
        x = (s2-s*s) // (2*s)
        print(x)

    else:
        if k==1:
            print("IMPOSSIBLE")
        else:
            while True:
                x = random.randint(-10000, 10000)
                if s+x == 0: continue
                if ((s+x)*(s+x)-(s2+x*x)) % (2*(s+x)):
                    continue
                y = ((s+x)*(s+x)-(s2+x*x))//(2*(s+x))
                print(x, y)
                break

