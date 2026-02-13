import sys
input = lambda: sys.stdin.readline().rstrip()


while True:
    try:
        s, t = input().split()
    except:
        break
    idx = 0
    for i in t:
        if i == s[idx]: idx += 1
        if idx == len(s): break
    if idx == len(s): print("Yes")
    else: print("No")
