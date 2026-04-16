import sys
input = lambda: sys.stdin.readline().rstrip()

ball = {}

m = int(input())
for _ in range(m):
    q = [*map(int, input().split())]
    if q[0] == 1:
        ball[q[2]] = q[1]
    else:
        print(ball[q[1]])
