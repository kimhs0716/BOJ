import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))

m = int(input())
for tc in range(m):
    v, t = map(int, input().split())
    v /= t

    ans = float('inf')

    for i in range(1 << n):
        f = 0
        c = 0
        idx = 0
        while i:
            if i & 1:
                f += arr[idx][0]
                c += arr[idx][1]
            idx += 1
            i >>= 1
        if f >= v:
            ans = min(ans, c)

    if ans == float('inf'):
        ans = 'IMPOSSIBLE'

    print(f'Case {tc + 1}: {ans}')

