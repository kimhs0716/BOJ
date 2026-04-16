import sys

input = lambda : sys.stdin.readline().rstrip()


n = int(input())
v = 0
s = 0
arr = [list(map(int, input().split())) for _ in range(n)]
for a, t in arr:
    vp = v + a * t
    s += (v + vp) / 2 * t
    v = vp

m = s

arr.sort(key=lambda x: -x[0])
v, s = 0, 0
for a, t in arr:
    vp = v + a * t
    s += (v + vp) / 2 * t
    v = vp

print('%.1f' % (s - m))
