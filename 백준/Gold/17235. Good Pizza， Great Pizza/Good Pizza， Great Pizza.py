from decimal import Decimal
import sys
input = sys.stdin.readline
n = int(input())
t1_M = t2_M = -1e11
t1_m = t2_m = 1e11
for _ in range(n):
    x, y = map(int, input().split())
    t1 = y - x
    t2 = y + x
    t1_M = max(t1_M, t1)
    t1_m = min(t1_m, t1)
    t2_M = max(t2_M, t2)
    t2_m = min(t2_m, t2)

d = Decimal(max(abs(t1_M - t1_m), abs(t2_M - t2_m)))
print(d * d / 2)
