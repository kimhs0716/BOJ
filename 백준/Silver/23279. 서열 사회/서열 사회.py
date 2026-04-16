import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()

n, k = map(int, input().split())
for r in range(k):
    m, *arr = list(map(int, input().split()))
    arr.sort()
    ans = []
    for i in range(m):
        ans.append(arr[i] + i + 1)
    print(' '.join(map(str, ans)))
