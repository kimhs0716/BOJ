import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

n, m = map(int, input().split())
jw = sum(map(int, input().split()))

arr = [[sum(map(int, input().split())), i] for i in range(1, n + 1)]
for i in range(n):
    if arr[i][0] > jw: arr[i][0] = 0
arr = list(filter(lambda x: x[0], arr))
arr.sort(reverse=True)
print(0)
for i in arr[:m - 1]:
    print(i[1])
