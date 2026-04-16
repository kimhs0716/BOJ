from math import pi, atan2

tau = 2 * pi

t = int(input())

for _ in range(t):
    n = int(input())
    ans = 0
    for __ in range(n):
        x1, y1, x2, y2 = map(int, input().split())
        theta1 = atan2(y1, x1)
        theta2 = atan2(y2, x2)
        d = min((theta1 - theta2) % tau, (theta2 - theta1) % tau)
        ans += d
    print('%.5f' % (ans / tau))