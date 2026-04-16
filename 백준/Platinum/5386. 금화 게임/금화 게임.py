import sys
input = sys.stdin.readline

def g(x, k):
    if k % 2:
        return (0, 1)[x % 2]
    pattern_len = k + 1
    if x % pattern_len == pattern_len - 1:
        return 2
    return (0, 1)[x % pattern_len % 2]

tc = int(input())
for i in range(tc):
    x, k = map(int, input().split())
    a = g(x, k)
    if a == 0: print(0)
    else:
        kk = 1
        while True:
            b = g(x - kk, k)
            if b == 0:
                print(kk)
                break
            kk *= k