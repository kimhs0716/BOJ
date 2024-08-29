import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


n = int(input())
arr = list(map(int, input().split()))

m = int(input())
for _ in range(m):
    l, r = map(int, input().split())
    carr = arr[:]
    cur = l
    for i in range(n):
        if l <= carr[i] <= r:
            carr[i] = cur
            cur += 1
    print(*carr)