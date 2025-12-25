import sys
input = lambda: sys.stdin.readline()[:-1]

import random

for tc in range(1, int(input())+1):
    ans = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    n = int(input())
    arr = input().split()
    ok = [[1]*26 for _ in range(26)]
    flag = True
    for pw in arr:
        if len(pw) == 1:
            flag = False
            break
        if len(pw) == 2:
            ok[ord(pw[0])-65][ord(pw[1])-65] = 0
    for i in range(26):
        if not any(ok[i]):
            flag = False
            break
    print(f"Case #{tc}: ")
    if not flag:
        print("IMPOSSIBLE")
        continue
    for _ in range(10000):
        random.shuffle(ans)
        s = ''.join(ans)
        if any(map(lambda x: x in s, arr)): continue
        print(s)
        break
    else:
        print("IMPOSSIBLE")
