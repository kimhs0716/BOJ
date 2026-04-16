from itertools import permutations as p
from math import sin, cos, pi

def cross(a, b, c):
    return (a[0] * b[1] + b[0] * c[1] + c[0] * a[1]) - \
           (b[0] * a[1] + c[0] * b[1] + a[0] * c[1])


cnt = 0

arr = list(map(int, input().split()))

for i in p(range(8)):
    poly = []
    for j in range(8):
        poly.append((arr[i[j]] * sin(pi / 4 * j), arr[i[j]] * cos(pi / 4 * j)))

    if all(map(lambda x: cross(poly[x - 1], poly[x], poly[(x + 1) % 8]) < 0, \
               range(8))):
        cnt += 1
        
print(cnt)
