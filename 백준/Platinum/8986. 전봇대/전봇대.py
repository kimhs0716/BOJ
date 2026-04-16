import sys
input = lambda: sys.stdin.readline().rstrip()

m = 1
n = int(input())
M = 1e10
arr = tuple(map(int, input().split()))

def pred(t):
    return sum(map(lambda x: abs(t * x - arr[x]), range(n)))

while True:
    mid1 = ((2 * m + M) / 3)
    mid2 = ((m + 2 * M) / 3)
    if mid1 + 0.9 >= mid2: break
    s0, s1, s2 = map(lambda t: pred(t), (m, mid1, mid2))
    if s0 >= s1 and s1 >= s2: m = mid1
    else: M = mid2

s = [int(m + i) for i in range(-3, 5)]
ss = map(lambda t: pred(t), s)
print(min(ss))
