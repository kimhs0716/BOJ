import sys
input = lambda: sys.stdin.readline()[:-1]

h, m = map(int, input().split())
cur = h*60+m

n = int(input())
bus = [list(map(int, input().split())) for _ in range(n)]

while 1:
    for x, y, d in bus:
        s = x*60+y
        if cur>=s and (cur-s)%d==0:
            print(f"{(cur//60)%24:02d}:{cur%60:02d}")
            exit()
    cur += 1
    if cur == 1440: cur = 0
