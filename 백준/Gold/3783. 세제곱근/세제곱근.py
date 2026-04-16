import sys
input = lambda: sys.stdin.readline().rstrip()

t = int(input())
for _ in range(t):
    n = int(input())
    m, M = 0, int('1'+'0'*70)
    n *= int('1'+'0'*36)
    while True:
        mid = (m + M) // 2
        # print(m, mid, M)
        # input()
        if m + 1 == M:
            if M ** 3 == n: mid = M
            break
        if mid ** 3 < n: m = mid
        else: M = mid
    print('%d.%010d' % (mid // 1000000000000, mid % 1000000000000 // 100))
