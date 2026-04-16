import sys
input = lambda: sys.stdin.readline().rstrip()

m = 0
n = int(input())
M = 1e13
arr1 = tuple(map(int, input().split()))
arr2 = tuple(map(int, input().split()))

def pred(t):
    s = 0
    for i in range((n - 1) // 2):
        s += abs(arr1[i] - (t + (n - 1) // 2 - i))
        s += abs(arr2[i] - (t + (n - 1) // 2 - i))
        s += abs(arr1[n - i - 1] - (t + (n - 1) // 2 - i))
        s += abs(arr2[n - i - 1] - (t + (n - 1) // 2 - i))
    s += abs(arr1[(n - 1) // 2] - t) + abs(arr2[(n - 1) // 2] - t)
    return s
    
while True:
    mid1 = ((2 * m + M) / 3)
    mid2 = ((m + 2 * M) / 3)
    if mid1 + 0.9 >= mid2: break
    s0, s1, s2 = map(lambda t: pred(t), (m, mid1, mid2))
    if s0 >= s1 and s1 >= s2: m = mid1
    else: M = mid2

s = [int(m + i) for i in range(-3, 5) if m + i >= 0]
ss = map(lambda t: pred(t), s)
print(min(ss))
