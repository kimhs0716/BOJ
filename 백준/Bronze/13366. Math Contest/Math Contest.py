import sys
input = lambda: sys.stdin.readline().rstrip()


for _ in range(int(input())):
    n = input()
    s = 0
    for i in n:
        s += int(i)
    print("NYOE S"[s%9==0::2])
